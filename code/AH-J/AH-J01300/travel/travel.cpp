#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e5 + 2;
const int M = 1e2 + 2;
const int INF = 0x3f3f3f3f;
string c1, s1, c2, s2, d1, d2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		printf("1");
		d1 = s1[0] + s1[1], d2 = s2[0] + s2[1];
		if (d1 == d2) {
			printf("1");
			int t1 = (s1[2] >= 'A' && s1[2] <= 'C') ? 0 : 1;
			int t2 = (s2[2] >= 'A' && s2[2] <= 'C') ? 0 : 1;
			if (t1 == t2) {
				printf("1");
				if (s1[2] == 'D') {
					s1[2] = 'E';
				}
				if (s2[2] == 'D') {
					s2[2] = 'E';
				}
				if (abs(s1[2] - s2[2]) == 1) {
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
