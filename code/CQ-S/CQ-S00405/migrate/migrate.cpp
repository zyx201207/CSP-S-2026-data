/*
luogu uid:1020627
miaomiaomiao 
*/
#include <bits/stdc++.h>
using ll = long long;
using pii = std::pair<int, int>;

namespace sub {
	const int N = 5000 + 10, MOD1 = 998244353, MOD2 = 1e9 + 7;
	ll a[N], dis[N], f1[N], f2[N]; std::vector<int> e[N];
	void add(int u, int v) { e[u].emplace_back(v), e[v].emplace_back(u); }
	void dijkstra(int st) {
		memset(dis, 0x3f, sizeof dis), memset(f1, 0, sizeof f1), memset(f2, 0, sizeof f2), dis[st] = 0, f1[st] = f2[st] = 1;
		std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq; pq.emplace(0, st); 
		while (!pq.empty()) {
			int u = pq.top().second; pq.pop();
			for (int v : e[u]) {
				if (dis[v] > dis[u] + 1) dis[v] = dis[u] + 1, f1[v] = f1[u], f2[v] = f2[u], pq.emplace(dis[v], v);
				else if (dis[v] == dis[u] + 1) (f1[v] += f1[u]) %= MOD1, (f2[v] += f2[u]) %= MOD2;
			}
		}
	}
	
	void solve() {
		int n; ll d; std::cin >> n >> d;
		for (int i = 1; i <= n; i++) std::cin >> a[i];
		for (int i = 1; i <= n; i++) {
			// [x - d, x + d]
			int R = std::upper_bound(a + 1, a + 1 + n, a[i] + d) - a - 1;
//			std::cout << "[" << i << ", " << R << "]\n";
			for (int p = i + 1; p <= R; p++) add(i, p);
		} 
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			dijkstra(i);
			for (int p = i + 1; p <= n; p++) if (f1[p] == f2[p] && f1[p] == 2) ans++;
//			std::cout << "i = " << i << '\n';
//			for (int p = 1; p <= n; p++) std::cout << f1[p] << " \n"[p == n];
		}
		std::cout << ans << '\n';
		for (int i = 1; i <= n; i++) e[i].clear();
	}
	int mian() {
		int T; std::cin >> T;
		while (T--) solve();
		return 0;
	}
}

namespace sub1 {
	void solve() {
		std::cout << "0\n";
	}
	int mian() {
		int T; std::cin >> T;
		while (T--) solve();
		return 0;
	}
}

int main() {
	freopen("migrate.in", "r", stdin), freopen("migrate.out", "w", stdout);
	std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
	int c; std::cin >> c;
	if (c <= 10) return sub::mian();
	else if (c == 13 || c == 14) return sub1::mian(); 
	return 0;
}
/*
注意到 n^2 有 40pts。 
力竭了 
*/
