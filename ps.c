#include "types.h"
#include "user.h"
#include "processInfo.h"
#include "stddef.h"



int main(void)
{
	struct processInfo info; 
	int pid; 

	printf(1, "Total number of active processes: %d\n", NumProcess());
	printf(1, "Maximum PID: %d\n", MaxPID());
	printf(1, "PID        STATE        PPID        SZ        NFD        NRSWITCH\n");

	
	for(int i=1; i<=MaxPID(); i++)
	{
		char state[7];
		pid = i;
		if (getProcInfo(pid, &info) == 0) 
		{
			if (info.state == 1) strcpy(state, "EMBRYO  ");
			else if (info.state == 2) strcpy(state, "SLEEP   ");
			else if (info.state == 3) strcpy(state, "RUNNABLE");
			else if (info.state == 4) strcpy(state, "RUN     ");
			else if (info.state == 2) strcpy(state, "ZOMBIE  ");
			printf(1, "%d          %s      %d         %d       %d         %d\n", pid, state, info.ppid, info.sz, info.nfd, info.nrswitch);
		}
			
	}

	//getProcInfo()
	exit();
}
