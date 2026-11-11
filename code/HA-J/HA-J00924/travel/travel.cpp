#include<bits/stdc++.h>
using namespace std;

const int N = 100;
char s1[N], c1[N], s2[N], c2[N];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%s %s %s %s", s1 + 1, c1 + 1, s2 + 1, c2 + 1);
	int ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;
	if (s1[1] == s2[1] && s1[2] == s2[2]) {
		ans1 = 1;
		if (c1[1] == c2[1] && c1[2] == c2[2]) {
			ans2 = 1;
			if (c1[1] == c2[1] && c1[2] == c2[2]) {
				ans2 = 1;
				if (c1[3] < 'D' && c2[3] < 'D') {
					ans3 = 1;
					if (abs(c1[3] - c2[3]) == 1) {
						ans4 = 1;
					}
				} else {
					if ((c1[3] == 'D' && c2[3] == 'E') || ((c1[3] == 'E' && c2[3] == 'D'))) {
						ans3 = 1;
						ans4 = 1;
					}
				}
			}
		}
	}
	printf("%d%d%d%d\n", ans1, ans2, ans3, ans4);
	return 0;
}
