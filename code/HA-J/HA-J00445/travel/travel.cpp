#include <bits/stdc++.h>
using namespace std;

const int C = 20;
char c1[C], s1[C], c2[C], s2[C];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%s%s%s%s", c1, s1, c2, s2);
	if (c1[0] == c2[0] && c1[1] == c2[1]) {
		int x = 10 * (s1[0] - '0') + s1[1] - '0';
		int y = 10 * (s2[0] - '0') + s2[1] - '0';
		if (s1[2] != s2[2] && x == y)
			if ((s1[2] == 'C' && s2[2] == 'D') || (s1[2] == 'D' && s2[2] == 'C'))
				printf("1100");
			else
				if (abs(s1[2] - s2[2]) == 1)
					printf("1111");
				else
					printf("1110");
		else
			printf("1000");
	} else
		printf("0000");
	return 0;
}
