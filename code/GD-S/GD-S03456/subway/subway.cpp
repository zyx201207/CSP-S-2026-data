// Created by YoungL
// Date: 10/31/2026
#include <bits/stdc++.h>
//#define ONLINE_JUDGE
#define FILENAME "subway"

using ll = long long;
constexpr int N = 500 + 5;
constexpr int M = 5e5 + 5;
constexpr ll inf = 1e18;
int n, m, q;
int w[M];    // BUT ANS SHOULD BE LONG LONG
int t[M][N];
ll dis[N][N]; // all inf except [i][i]
std::vector<int> con[M]; // lines that has i

inline void build() {
	for (int i = 1; i <= n; ++i) {
		std::fill(dis[i] + 1, dis[i] + 1 + n, inf);
		dis[i][i] = 0;
	}
	for (int u = 1; u <= m; ++u) {
		// d^2
		for (auto i : con[u]) {
			for (auto j : con[u]) {
				if (i == j) continue;
				dis[i][j] = std::min(
					dis[i][j], 
					(ll) t[u][i] + (ll) t[u][j]
				);
			}
		}
	}
}

inline void floyd() {
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
}

inline ll get_ans(int x, int y) {
	ll ans = inf;
	for (auto i : con[x]) {
		for (auto j : con[y]) {
			ll now = (ll) w[x] + (ll) w[y];
			now += dis[i][j];
			now += (ll) t[x][i] + (ll) t[y][j];
			ans = std::min(ans, now);
			
//			std::cerr << "station: " << i << ", " << j << "\n";
//			std::cerr << w[x] << " + " << t[x][i] << "\n";
//			std::cerr << "DIS: " << dis[i][j] << "\n";
//			std::cerr << t[y][j] << " + " << w[y] << "\n";
//			std::cerr << "\n";
		}
	}
	return ans;
}

inline void solve() {
	int _c, _d;
	std::cin >> _c >> n >> m >> _d >> q;
//	std::cout << _c << " " << n << " " << m << " " << _d << " " << q << "\n";
	
	// _c, _d useless
	(void)_c;
	(void)_d;
	
	for (int i = 1; i <= m; ++i) {
		std::cin >> w[i];
//		std::cout << w[i] << " \n"[i == m];
	}
	
	for (int i = 1; i <= n; ++i) {
		int k;
		std::cin >> k;
		for (int j = 1; j <= k; ++j) {
			int A, T;
			std::cin >> A >> T;
			t[A][i] = T;
			con[A].push_back(i);
		}
	}
	
	build();
	floyd();
	
	while (q--) {
		int x, y;
		std::cin >> x >> y;
//		std::cout << x << " " << y << "\n";
		std::cout << get_ans(x, y) << "\n";
//		std::cerr << "DW " << x << " " << y << "\n";
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);
	freopen(FILENAME ".err", "w", stderr);
#endif

	std::cin.tie(0);
	std::cout.tie(0);
	std::ios::sync_with_stdio(0);

	solve();

	return 0;
}

