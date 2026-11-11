#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
int cas, twt, n, d, x[N], f[N], g[N][2];
void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
		g[i][0] = g[i][1] = 0;
	}
	for (int i = 1; i <= n; i++) {
		int lb = i, ub = n + 1, mid;
		while (ub - lb > 1) {
			mid = ub + lb >> 1;
			if (x[mid] - x[i] <= d) lb = mid;
			else ub = mid;
		}
		f[i] = lb;
	}
	for (int i = 1; i < n; i++) {
		g[i][0] += 1;
		g[f[i]][0] += 1;
		if (f[f[i]] == f[f[i] - 2] or f[i] == n) {
			continue;
		}
		if (f[f[i]] != f[f[i] - 1]) {
			g[f[f[i]]][0] += g[i][0];
			g[f[f[i]]][1] += g[i][1];
		} else {
			g[f[f[i]]][1] += g[i][0];
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) if (f[i] != n) {
		int x = i - 1, y = f[f[i] - 1], z = f[f[i]];
		if (f[i] > 2) x = max(x, f[f[i] - 2]); 
		ans += g[i][0] * (y - x) + g[i][1] * (z - y);
	}
	cout << ans << '\n';
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> cas >> twt;
	while (twt--) solve();
}
