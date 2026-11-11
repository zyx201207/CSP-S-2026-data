#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int s1, s2;
	char c1[3];
	char c2[3];
	scanf("%d %c%c%c %d %c%c%c", &s1, &c1[0], &c1[1], &c1[2], &s2, &c2[0], &c2[1], &c2[2]);
	if(c1[2] == 'D')
	{
		c1[2] = 'E';
	}
	if(c2[2] == 'D')
	{
		c2[2] = 'E';
	}
	if(s1 == s2)
	{
		printf("1");
	}
	else
	{
		printf("0");
	}
	if(c1[0] == c2[0] && c1[1] == c2[1])
	{
		printf("1");
		if((c1[2] >= 'A' && c1[2] <= 'C' && c2[2] >= 'A' && c2[2] <= 'C') || (c1[2] >= 'E' && c1[2] <= 'F' && c2[2] >= 'E' && c2[2] <= 'F'))
		{
			printf("1");
			if(c1[2]+1 == c2[2] || c1[2]-1 == c2[2])
			{
				printf("1");
			}
			elseS
			{
				printf("0");
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
	return 0;
}
