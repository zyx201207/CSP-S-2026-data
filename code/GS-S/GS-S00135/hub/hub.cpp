#include <iostream>

int man(void)
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c = 0,T = 0;
	scanf("%d",&T);
	while(T--)
	{
		int n = 0,k =0;
		scanf("%d%d",&n,&k);
		printf("%d\n",n - k);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
