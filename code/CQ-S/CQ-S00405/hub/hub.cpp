/*
luogu uid:1020627
miaomiaomiao 
*/
#include <bits/stdc++.h>

namespace sub {
	const int N = 10 + 2;
	std::vector<int> e[N];
	int dep[N], fa[N][5];
	void dfs(int u, int p) {
		dep[u] = dep[p] + 1, fa[u][0] = p;
		for (int i = 0; fa[u][i]; i++) fa[u][i + 1] = fa[fa[u][i]][i];
		for (int v : e[u]) if (v != p) dfs(v, u);
	}
	int lca(int u, int v) {
		if (dep[u] < dep[v]) std::swap(u, v);
		for (int i = 4; ~i; i--) if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
		if (u == v) return u;
		for (int i = 4; ~i; i--) if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
		return fa[u][0];
	}
	int count; std::set<int> s;
	void get(int u, int p, int op) {
		if (!op && s.count(u)) op = 1, count++;
		if (!s.count(u)) op = 0;
		for (int v : e[u]) {
			if (v == p) continue;
			get(v, u, op);
		}
	}
	
	int dis[N][N];
	void solve() {
		int n, k; std::cin >> n >> k;
		for (int i = 1; i < n; i++) {
			int u, v; std::cin >> u >> v;
			e[u].emplace_back(v), e[v].emplace_back(u);
		} dfs(1, 0);
		int ans = 0x3f3f3f3f;
		for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) dis[i][j] = dep[i] + dep[j] - 2 * dep[lca(i, j)];
		for (int S = 0; S < (1 << n); S++) {
			if (__builtin_popcount(S) != k) continue;
			s.clear();
			for (int i = 0; i < n; i++) if ((S >> i) & 1) s.insert(i + 1); 
			count = 0, get(1, 0, 0);
			if (count > 2) continue;
			int res = 0;
			for (int i = 1; i <= n; i++) {
				int d = 0x3f3f3f3f;
				for (int j : s) {
					d = std::min(d, dis[i][j]);
				}
				if (s.count(i)) d = 0;
				res = std::max(res, d);
			}
			ans = std::min(ans, res);
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
	const int N = 100000 + 10;
	std::vector<int> e[N];
	int dep[N];
	void dfs(int u, int p) {
		dep[u] = dep[p] + 1;
		for (int v : e[u]) if (v != u) dfs(v, u);
	}
	
	void solve() {
		int n, k; std::cin >> n >> k;
		for (int i = 1; i < n; i++)	{
			int u, v; std::cin >> u >> v;
			e[u].emplace_back(v), e[v].emplace_back(u); 
		} int id = 1, id1 = 1; for (int i = 1; i <= n; i++) if (dep[i] > dep[id]) id = i;
		dfs(id, 0);
		for (int i = 1; i <= n; i++) if (dep[i] > dep[id1]) id1 = id;
	}
	int mian() {
		int T; std::cin >> T;
		while (T--) solve();
		return 0;
	}
}

int main() {
	freopen("hub.in", "r", stdin), freopen("hub.out", "w", stdout);
	std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
	int c; std::cin >> c;
	if (c <= 3) return sub::mian();
	if (c == 7 || c == 11 || c == 12) return sub1::mian();
	return 0;
}
/*
最后 30min，我还能蒸 
我发现我不会判连通 
我发现我想的错完了
并非找直径上的两个端点 
*/
