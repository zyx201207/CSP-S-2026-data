#include <cstdio>
using namespace std;

bool pd(char x[],char y[])
{
	for(int i=0;i<=1;i++)
	{
		if(x[i]!=y[i])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1[3],s1[4],c2[3],s2[4];
	scanf("%s %s %s %s",c1,s1,c2,s2);
	s1[2]-=1;
	s2[2]-=1;
	if(pd(c1,c2))
	{
		printf("1");
		if(pd(s1,s2))
		{
			printf("1");
			if((s1[2]=='C'&&s2[2]=='D')||s1[2]=='C'&&s2[2]=='D')printf("00");
			else
			{
				printf("1");
				if(s1[2]-s2[2]==1||s2[2]-s1[2]==1)printf("1");
				else printf("0");
			}
		}
		else printf("000");
	}
	else printf("0000");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
