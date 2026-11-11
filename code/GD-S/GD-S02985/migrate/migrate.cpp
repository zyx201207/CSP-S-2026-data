#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 10;
int c, t, n, d, x[N];
void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	if (n == 1) {
		cout << 0 << '\n';
		return;
	}
	int k = d / abs(x[2] - x[1]);
	if (abs(x[2] - x[1]) > d || k == 1 || k == n) {
		cout << 0 << '\n';
		return;
	}
	cout << n - k * 2 + 1 << '\n';
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while (t--) {
		solve();
	}
	return 0;
}
