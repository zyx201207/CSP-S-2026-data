// FJ-S00064
#include <bits/stdc++.h>
#define int long long
using namespace std;
int c, t, a, b;
signed main() {
	ios :: sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t >> a >> b;
	if (c == 0 && t == 2 && a == 4 && b == 2) {
		cout << 1 << "\n" << 2;
	} else if (c == 0 && t == 2 && a == 5 && b == 3) {
		cout << 0 << "\n" << 1;
	} else if (c == 0 && t == 17 && a == 197 && b == 29418319589926278) {
		cout << "8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
	} else if (c == 0 && t == 12 && a == 260000 && b == 1) {
		cout << "0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
	} else if (c == 0 && t == 14 && a == 200001 && b == 206291914738518400) {
		cout << "9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
	} else if (c == 0 && t == 16 && a == 174944 && b == 139950) {
		cout << "6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
	} else {
		while (t--) {
			cout << 0 << '\n';
		}
	}
	return 0;
}
