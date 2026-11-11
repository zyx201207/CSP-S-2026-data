#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool b1 = (c1 == c2);
	cout << b1;
	string p1 = s1.substr(0, 2), p2 = s2.substr(0, 2);
	char z1 = s1[2], z2 = s2[2];
	bool b2 = (b1 && (p1 == p2));
	cout << b2;
	bool l1 = (z1 >= 'A' && z1 <= 'C'), l2 = (z2 >= 'A' && z2 <= 'C');
	bool b3 = (b2 && ((l1 == l2) || (!l1 && !l2)));
	if (b3) {
		cout << 1;
		if (z1 == z2 + 1 || z1 == z2 - 1) cout << 1;
		else if ((z1 == 'D' && z2 == 'F') || (z1 == 'F' && z2 == 'D')) cout << 1;
		else cout << 0;
	} else {
		cout << "00";
	}
	return 0;
}
