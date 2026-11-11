#include <cstdio>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	char s1[3],s2[3];
	scanf("%d %s %d %s",&c1,s1,&c2,s2);
	if(c1==c2)
	{
		int n1=(s1[0]-'0')*10+s1[1]-'0';
		int n2=(s2[0]-'0')*10+s2[1]-'0';
		if(n1==n2)
		{
			if(s1[2]<='C'&&s2[2]<='C')
			{
				if((s1[2]-s2[2]==1)||(s2[2]-s1[2]==1))
				{
					printf("1111");
				}
				else
				{
					printf("1110");
				}
			}
			else if(s1[2]>='D'&&s2[2]>='D')
			{
				printf("1111");
			}
			else
			{
				printf("1100");
			}
		}
		else
		{
			printf("1000");
		}
	}
	else
	{
		printf("0000");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
