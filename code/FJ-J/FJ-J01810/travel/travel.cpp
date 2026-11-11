#include <bits/stdc++.h>
using namespace std;
char c[20];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=10;i++)
	{
		cin >> c[i];
	}
	if(c[1]==c[6]&&c[2]==c[7])
	{
		printf("1");
		if(c[3]==c[8]&&c[4]==c[9])
		{
			printf("1");
			if(c[5]-'A'<=2&&c[10]-'A'<=2||c[5]-'A'>2&&c[10]-'A'>2)
			{
				printf("1");
				if(c[5]=='C'&&c[10]=='D')
				{
					printf("0");
				}
				else if(c[10]=='C'&&c[5]=='D')
				{
					printf("0");
				}
				else
				{
					if(abs(c[5]-'A'-(c[10]-'A'))==1)
					{
						printf("1");
					}
					else
					{
						printf("0");
					}
				}
			}
			else
			{
				printf("00");
			}
		}
		else
		{
			printf("000");
		}
	}
	else
	{
		printf("0000");
	}
	return 0;
}
