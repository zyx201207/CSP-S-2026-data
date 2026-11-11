#include <bits/stdc++.h>
using namespace std;
int ch[100] = {0, 0, 0, 1, 1, 1};
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c1, s1, c2, s2;
	char ch1, ch2;
	scanf("%d%d%c%d%d%c", &c1, &s1, &ch1, &c2, &s2, &ch2);
	if(c1 == c2) {
		printf("1");
		if(s1 == s2) {
			printf("1");
			if(ch[ch1 - 'A'] == ch[ch2 - 'A']) {
				printf("1");
				if(ch[ch1 - 'A'] == 1 || (ch[ch1 - 'A'] == 0 && abs(ch1 - ch2) ==1)) {
					printf("1");
				} else {
					printf("0");
				}
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
