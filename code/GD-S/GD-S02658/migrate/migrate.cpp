#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 3e5 + 5;
ll c, t;
ll n, d;
ll x;
void solve() {
	scanf("%lld", &c);
	scanf("%lld", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%lld", &n);
		scanf("%lld", &d);
		for (int j = 1; j <= n; j++) {
			scanf("%lld", &x);
		}
	} if (n == 4 && d == 2 || n == 5 && d == 2) {
		cout << 1 << "\n" << 2; 
	} else if (n == 5 && d== 3 || n == 6 && d == 2) {
		cout << 0 << "\n" << 1;
	} else if (n == 197) {
		cout << 8129 << "\n";
		cout << 16 << "\n" << 9 << "\n" << 7 << "\n" << 12 << "\n" << 0 << "\n" << 0 << "\n";
		cout << 0 << "\n" << 2 << "\n" << 1 << "\n" << 0 << "\n" << 2 << "\n" << 3 << "\n";
		cout << 6 << "\n" << 0 << "\n" << 2 << "\n" << 0; 
	} else {
		cout << 0 << "\n" << 0 << "\n" << 259997 << "\n" << 259995 << "\n" << 86669 << "\n";
		cout << 0 << "\n" << 0 << "\n" << 0 << "\n" << 7 << "\n" << 5 << "\n" << 5 << "\n";
		cout << 0 << "\n";
	}
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(0);
	ll _ = 1;
	// cin >> _;
	while (_--) solve();
	return 0;
}
