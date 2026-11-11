#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
bool b[4];
int main() {
	freopen("travel.in", "r", stdin);	 	
	freopen("travel.out", "w", stdout);
	string ans;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1[0] == c2[0] && c1[1] == c2[1]) {
		b[0] = 1;
	} else {
		b[0] = 0;
	}
	if (s1[0] == s2[0] && s1[1] == s2[1] && b[0] == 1) {
		b[1] = 1;
	} else {	
		b[1] = 0;
	}
	if (((s1[2] >= 'A' && s1[2] <= 'C') && (s2[2] >= 'A' && s2[2] <= 'C') && b[1] == 1) || ((s1[2] >= 'D' && s1[2] <= 'F') && (s2[2] >= 'D' && s2[2] <= 'F') && b[1] == 1)) {
		b[2] = 1;
	} else {
		b[2] = 0;
	}
	char x = s1[2], y = s2[2];
	if ((x + 1 == y || y + 1 == x || x - 1 == y || y - 1 == x) || (x == 'D' && y == 'F') || (x == 'F' && y == 'D') && b[2] == 1) {
		b[3] = 1;
	} else {
		b[3] = 0;
	}
	for (int i = 0; i <= 3; i ++) {
		if (b[i]) {
			ans += '1';
		}
		else {
			ans += '0';
		}
	}
	cout << ans;
	return 0;
}
