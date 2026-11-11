#include <bits/stdc++.h>

using ll = long long;

void solve(int _c) {
	int n, k;
	std::cin >> n >> k;
	
	std::vector<std::vector<int>> G(n + 1);
	for (int i = 1; i < n; i++) {
		int x, y;
		std::cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	
	if (_c == 7) {
		std::vector<int> dep(n + 1), mdep(n + 1);
		auto getd = [&](auto&& self, int x, int fa) -> void {
			mdep[x] = dep[x];
			for (auto& y : G[x]) {
				if (y == fa) continue;
				dep[y] = dep[x] + 1;
				self(self, y, x);
				mdep[x] = std::max(mdep[x], mdep[y]);
			}
		};
		
		int ans = n;
		auto dfs = [&](auto&& self, int x, int fa) -> void {
			int maxn = dep[x];
			for (auto& y : G[x]) {
				if (y == fa) continue;
				maxn = std::max(maxn, mdep[y] - dep[x]);
			}
			
			if (dep[x] == maxn) {
				ans = std::min(ans, dep[x]);
				return;
			}
			for (auto& y : G[x]) {
				if (y == fa) continue;
				if (mdep[y] - dep[x] == maxn) {
					self(self, y, x);
					return;
				}
			}
		};
		
		for (int i = 1; i <= n; i++) {
			getd(getd, i, 0);
			dfs(dfs, i, 0);
		}
		std::cout << ans << "\n";
		return;
	}
	
	int ans = n;
	for (int i = 0; i < (1 << n); i++) {
		if (__builtin_popcount(i) != k) {
			continue;
		}
		
		std::vector<int> b(n + 1);
		for (int j = 1; j <= n; j++) {
			if ((i >> (j - 1)) & 1) {
				b[j] = 1;
			}
		}
		
		std::vector<int> vis(n + 1);
		auto dfs = [&](auto&& self, int x) -> void {
			vis[x] = 1;
			for (auto& y : G[x]) {
				if (!vis[y] && b[y]) {
					self(self, y);
				}
			}
		};
		
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (b[j] && !vis[j]) {
				cnt++;
				dfs(dfs, j);
			}
		}
		if (cnt > 2) continue;
		
		std::vector<int> dist(n + 1, -1);
		std::queue<int> q;
		for (int j = 1; j <= n; j++) {
			if ((i >> (j - 1)) & 1) {
				dist[j] = 0;
				q.push(j);
			}
		}
		
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (auto& y : G[x]) {
				if (dist[y] == -1) {
					dist[y] = dist[x] + 1;
					q.push(y);
				}
			}
		}
		
		int maxn = 0;
		for (int i = 1; i <= n; i++) {
			maxn = std::max(maxn, dist[i]); 
		}
		ans = std::min(ans, maxn);
	}
	
	std::cout << ans << "\n";
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int c, t;
	std::cin >> c >> t;
	while (t--) solve(c);
	return 0;
}
