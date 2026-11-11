#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, a[N];
int vis[N], res, cnt, p[40];
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	p[0] = 1;
	for (int i = 1; i < 30; ++i) p[i] = p[i - 1] << 1;
	for (int j = 29; j >= 0; --j) {
		cnt = 0;
		for (int i = 1; i <= n; ++i) {
			if (vis[i]) continue;
			if ((a[i] >> j) & 1) ++cnt;
		}
		if (cnt < m) continue;
		res += p[j];
		for (int i = 1; i <= n; ++i) {
			if ((a[i] >> j) & 1) continue;
			vis[i] = 1;
		}
	}
	cout << res << '\n';
	return 0;
} 
