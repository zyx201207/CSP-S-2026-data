#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2  >> s2;
	if (c1 == c2) cout << 1;
	else {
		cout << "0000" ;
		return 0;
	}
	if (s1[0] == s2[0] && s1[1] == s2[1]) cout << 1;
	else {
		cout << "000";
		return 0;
	}
	bool cmp1 = true, cmp2 = true;
	if (s1[2] == 'D' || s1[2] == 'F') cmp1 = false;
	if (s2[2] == 'D' || s2[2] == 'F') cmp2 = false;
	if (cmp1 == cmp2) cout << 1;
	else {
		cout << "00";
		return 0;
	}
	int a = s1[2], b = s2[2];
	if (abs(a - b) == 1) cout << 1;
	else cout << 0;
	return 0;
}
