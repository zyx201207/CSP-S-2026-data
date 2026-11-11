#include <bits/stdc++.h>
using namespace std;

char s1[10], s2[10], c1[10], c2[10];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%s%s%s%s", c1 + 1, s1 + 1, c2 + 1, s2 + 1);
	if (c1[1] == c2[1] && c1[2] == c2[2]) {
		if (s1[1] == s2[1] && s1[2] == s2[2]) {
			if ((s1[3] <= 'C') == (s2[3] <= 'C')) {
				if (abs(s1[3] - s2[3]) == 1) {
					printf("1111\n");
				} else {
					printf("1110\n");
				}
			} else {
				printf("1100\n");
			}
		} else {
			printf("1000\n");
		}
	} else {
		printf("0000\n");
	}
	return 0;
}
