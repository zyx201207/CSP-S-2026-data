#include <cstdio>
using namespace std;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int aaa1, aaa2, bbb1, bbb2;
	char aaa3, bbb3;
	scanf("%d %d%c %d %d%c", &aaa1, &aaa2, &aaa3, &bbb1, &bbb2, &bbb3);
	if (aaa1 == bbb1)
	{
		if (aaa2 == bbb2)
		{
			if (((aaa3 == 'A' || aaa3 == 'B' || aaa3 == 'C') && 
			(bbb3 == 'A' || bbb3 == 'B' || bbb3 == 'C')) ||
			((aaa3 == 'D' || aaa3 == 'F') && 
			(bbb3 == 'D' || bbb3 == 'F')))
			{
				if ((aaa3 == 'A' && bbb3 == 'B') || 
				(aaa3 == 'B' && (bbb3 == 'A' || bbb3 == 'C')) ||
				(aaa3 == 'C' && bbb3 == 'B') ||
				(aaa3 == 'D' && bbb3 == 'F') ||
				(aaa3 == 'F' && bbb3 == 'D'))
				{
					printf("1111");
				}
				else
				{
					printf("1110");
				}
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
}