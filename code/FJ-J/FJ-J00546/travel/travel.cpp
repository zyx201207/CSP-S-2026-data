#include<bits/stdc++.h>
using namespace std;
bool flag1 = false, flag2 = false, flag3 = false, flag4 = false;
string c1, s1, c2, s2, line1, line2;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	flag1 = c1 == c2 ? true : false;
	line1 = s1[0] + s1[1];
	line2 = s2[0] + s2[1];
	flag2 = (line1 == line2 && flag1 == true) ? true : false;
	char h1 = s1[2], h2 = s2[2];
	if (flag2 == true && flag1 == true) {
		if (h1 == 'D' || h1 == 'F') {
			if (h2 == 'F' || h2 == 'D') flag3 = true;
		} else if (h1 == 'A' || h1 == 'B' || h1 == 'C') {
			if (h2 != 'D' && h2 != 'F') flag3 = true;
		}
	}
	if (flag1 == true && flag2 == true && flag3 == true) {
		int g1 = int(h1), g2 = int(h2);
		if (g1 + 1 == g2 || g1 - 1 == g2) flag4 = true;
	}
	cout << flag1 ? 1 : 0;
	cout << flag2 ? 1 : 0;
	cout << flag3 ? 1 : 0;
	cout << flag4 ? 1 : 0;
	return 0;
}
