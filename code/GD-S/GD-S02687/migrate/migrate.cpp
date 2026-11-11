#include <bits/stdc++.h>

const int N = 2e6 + 7;

int n, nxt[N];
long long d, a[N], f[N], g[N], h[N];

void solve() {
	std::cin >> n >> d;
	for (int i = 1; i <= n; ++i)
		std::cin >> a[i];
//	std::cout << '\n';
	a[0] = -4e18;
	for (int i = 1, p = 1; i <= n; ++i) {
		while (p < n && a[p + 1] <= a[i] + d)
			++p;
		nxt[i] = p;
	}
	long long ans = 0;
//	for (int i = 1; i <= n; ++i) {
//		for (int j = i + 1; j <= n; ++j) {
//			std::vector<int> p; int cnt = 0;
//			for (int u = i; u != j; u = std::min(nxt[u], j)) {
//				p.push_back(u);
//				if (u == nxt[u]) {
//					cnt = 2;
//					break;
//				}
//			}
//			p.push_back(j);
////			std::cout << i << ' ' << j << '\n';
//			for (int k = 1; k < p.size() - 1; ++k) {
//				int x = p[k - 1], y = p[k], z = p[k + 1];
//				if (a[z] <= a[y - 1] + d) {
//					++cnt;
//					if (x != i && a[y - 1] <= a[x - 1] + d)
//						++cnt;
//					if (a[z] <= a[y - 2] + d)
//						++cnt;
//				}
//			}
//			if (cnt == 1)
//				++ans;
//		}
//	}
	for (int i = n; i >= 1; --i) {
		f[i] = 0, g[i] = 0, h[i] = 0;
		if (nxt[i] == i)
			continue;
			
		int p = nxt[i];
		long long* p1 = std::upper_bound(a + p + 1, a + nxt[p] + 1, a[p - 1] + d);
		long long* p2 = std::upper_bound(a + p + 1, a + nxt[p] + 1, a[p - 2] + d);
		int fx = p1 - p2, hx = (a + nxt[p] + 1 - p1);

		if (nxt[p] != p && a[nxt[p]] <= a[p - 1] + d) {
//			std::cout << 'a' << p << '\n';
			if (a[i - 1] + d < a[p - 1])
				f[i] = fx;
			if (a[p - 2] + d < a[nxt[p]]) {
				if (a[i - 1] + d < a[p - 1])
					g[i] = h[p];
				ans += h[p];
			}
			h[i] = hx;
			ans += fx;
		} else {
			if (a[i - 1] + d < a[p - 1])
				f[i] = f[p] + fx;
			else
				f[i] = f[p];
			h[i] = h[p] + hx, g[i] = g[p];
			ans += f[p] + fx + g[i];
		}
//		std::cout << f[i] << ' ' << g[i] << ' ' << h[i] << ' ' << hx << ' ' << fx << '\n';
//		std::cout << i << ' ' << p << ' ' << ans << '\n';
	}
	std::cout << ans << '\n';
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	std::cin.tie(0), std::cout.tie(0), std::ios::sync_with_stdio(false);
	
	int c, t; std::cin >> c >> t; while (t--) solve();
	return 0;
}
/*
0 1
5 3
-3 0 2 3 4

0 1
10 3
0 3 6 7 8 9 10 13 16 19

0 1
10 3
0 3 6 7 8 9 10 11 14 17
*/
