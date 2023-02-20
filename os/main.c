#include "console.h"
#include "defs.h"
#include "loader.h"
#include "timer.h"
#include "trap.h"

void clean_bss()
{
	extern char s_bss[];
	extern char e_bss[];
	memset(s_bss, 0, e_bss - s_bss);
}

void main()
{
	clean_bss();
	printf("hello world!\n");
	proc_init();
	kinit();
	kvm_init();
	loader_init();
	trap_init();
	timer_init();
	load_init_app();
	infof("start scheduler!");
	scheduler();
}