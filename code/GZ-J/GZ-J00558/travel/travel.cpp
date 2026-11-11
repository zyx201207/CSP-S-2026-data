//GZ-J00558 ¶Îãå·²
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a[10] , s[10] , b[10] , t[10] ;
	scanf("%s %s %s %s", a , s , b , t ) ;
	if(a[0] == b[0] && a[1] == b[1])
	{
		printf("1");
		if(s[0] == t[0] && s[1] == t[1])
		{
			printf("1");
			if(s[2] >= 'A' && t[2] >= 'A' && s[2] <= 'C' && t[2] <= 'C')
			{
				printf("1");
				if(s[2] == 'B' || t[2] == 'B')
				{
					printf("1");
					return 0 ;
				}
				else
				{
					printf("0");
					return 0 ;
				}
			}
			else if((s[2] == 'D' && t[2] == 'F') || (s[2] == 'F' && t[2] == 'D'))
			{
				printf("11");
				return 0 ;
			}
			else
			{
				printf("00");
				return 0 ;
			}
		}
		else
		{
			printf("000");
			return 0 ;
		}
	}
	else
	{
		printf("0000");
		return 0 ;
	}
	return 0 ;
}
