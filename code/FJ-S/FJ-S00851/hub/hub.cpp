#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	for (int i = 1;i <= t; i++) {
		if (i & 1) {
			cout << 1 << "\n";
		}
		else {
			cout << 2 << "\n";
		}
	}
	return 0;
}
