#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
char s1[MAXN], s2[MAXN];
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, c2; 
	cin >> c1;
	for (int i = 1; i <= 3; ++i) {
		cin >> s1[i];
	}
	cin >> c2;
	for (int i = 1; i <= 3; ++i) {
		cin >> s2[i];
	}
	bool flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0;
	if (c1 == c2) {
		flag1 = 1;
		if (s1[1] == s2[1] && s1[2] == s2[2]) {
			flag2 = 1;
			if ((s1[3] == 'F' && s2[3] == 'D') || (s1[3] == 'D' && s2[3] == 'F') || (s1[3] == 'A' && s2[3] == 'C') || (s1[3] == 'A' && s2[3] == 'B') || (s1[3] == 'C' && s2[3] == 'A') || (s1[3] == 'C' && s2[3] == 'B') || (s1[3] == 'B' && s2[3] == 'A') || (s1[3] == 'B' && s2[3] == 'C')) {
				flag3 = 1;
				if ((s1[3] == 'F' && s2[3] == 'D') || (s1[3] == 'D' && s2[3] == 'F') || (s1[3] == 'A' && s2[3] == 'B') || (s1[3] == 'B' && s2[3] == 'A') || (s1[3] == 'B' && s2[3] == 'C') || (s1[3] == 'C' && s2[3] == 'B')) {
					flag4 = 1;
				}
			}
			
		}
	}
	cout << flag1 << flag2 << flag3 << flag4 << '\n';
	return 0;
}
