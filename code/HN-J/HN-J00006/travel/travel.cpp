#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

char c1[2], s1[3], c2[2], s2[3];
char ans[4];
map<char, int> ump;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	ump['A'] = 1;
	ump['B'] = 1;
	ump['C'] = 1;
	ump['D'] = 0;
	ump['F'] = 0;
	
	scanf("%s%s%s%s", c1, s1, c2, s2);
	if ((c1[0] == c2[0]) && (c1[1] == c2[1]))
	{
		ans[0] = '1';
		if ((s1[0] == s2[0]) && (s1[1] == s2[1]))
		{
			ans[1] = '1';
			if (ump[s1[2]] == ump[s2[2]])
			{
				ans[2] = '1';
				if ((s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'B' && s2[2] == 'A')) printf("1111");
				else if ((s1[2] == 'B' && s2[2] == 'C') || (s1[2] == 'C' && s2[2] == 'B')) printf("1111");
				else if ((s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D')) printf("1111");
				else printf("1110");
			}
			else printf("1100");
		}
		else printf("1000");
	}
	else printf("0000");
	
	return 0;
}
