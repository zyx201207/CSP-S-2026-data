#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 10;
int n, c, T, d, a[N], b[N], ans;
void solve() {
	cin >> n >> d;
	ans = 0;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	for (int i = 1; i <= n; i ++) b[i] = a[i] - a[i - 1];
	for (int i = 1; i <= n - 3; i ++) {
		if (b[i + 1] <= d && b[i + 2] <= d && b[i + 3] <= d) ans ++;
	}
	cout << ans << '\n';
}
signed main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> T;
	while (T --) {
		solve();
	}
	return 0;
}
