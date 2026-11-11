#include <bits/stdc++.h>
using namespace std;

char c1[10], c2[10], c3[10], c4[10];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%s%s%s%s", c1 + 1, c2 + 1, c3 + 1, c4 + 1);
	if (c1[1] == c3[1] && c1[2] == c3[2]) {
		printf("1");
		if (c2[1] == c4[1] && c2[2] == c4[2]) {
			printf("1");
			if ((c2[3] <= 'C' && c4[3] <= 'C') || (c2[3] >= 'D' && c4[3] >= 'D')) {
				printf("1");
				if ((c2[3] + 1 == c4[3]) || (c4[3] + 1 == c2[3]))
					printf("1");
				else
					printf("0");
			} else {
				printf("00");
			}
		} else {
			printf("000");
		}
	} else {
		printf("0000");
	}
	return 0;
}
