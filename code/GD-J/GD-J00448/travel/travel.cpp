#include <bits/stdc++.h>
using namespace std;

char c1[10], s1[10], c2[10], s2[10];

bool check(char a, char b) {
	if (a <= 'C') return a + 1 == b;
	return a + 2 == b;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%s%s%s%s", c1, s1, c2, s2);
	if (c1[0] == c2[0] && c1[1] == c2[1]) {
		printf("1");
		if (s1[0] == s2[0] && s1[1] == s2[1]) {
			printf("1");
			if ((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') ||
				(s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F')) {
				printf("1");
				if (check(s1[2], s2[2]) || check(s2[2], s1[2])) {
					puts("1");
				} else {
					puts("0");
				}
			} else {
				puts("00");
			}
		} else {
			puts("000");
		}
	} else {
		puts("0000");
	}
	return 0;
}