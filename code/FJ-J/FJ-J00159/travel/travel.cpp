#include <cstdio>
#include <string>
using namespace std;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	string c1, s1, c2, s2;
	c1.resize(3);s1.resize(4);
	c2.resize(3);s2.resize(4);
	scanf("%s %s %s %s", &c1[0], &s1[0], &c2[0], &s2[0]);
	
	if (c1 == c2)
	{
		printf("1");
		if (s1.substr(0, 2) == s2.substr(0, 2))
		{
			printf("1");
			if (s1[2] == 'A')
			{
				if (s2[2] == 'B' || s2[2] == 'C')
				{
					printf("1");if (s2[2] == 'B') printf("1");
					else printf("0");
				}
				else printf("00");
			}
			else if (s1[2] == 'B')
			{
				if (s2[2] == 'A' || s2[2] == 'C') printf("11");
				else printf("00");
			}
			else if (s1[2] == 'C')
			{
				if (s2[2] == 'B' || s2[2] == 'A')
				{
					printf("1");
					if (s2[2] == 'B') printf("1");
					else printf("0");
				}
				else printf("00");
			}
			else if (s1[2] == 'D')
			{
				if (s2[2] == 'F') printf("11");
				else printf("00");
			}
			else if (s1[2] == 'F')
			{
				if (s2[2] == 'D') printf("11");
				else printf("00");
			}
			else printf("00");
		}
		else printf("000");
	}
	else printf("0000");
	
	return 0;
}
