#include <bits/stdc++.h>
#define int long long
#define pii std::pair< int, int >
const int N = 1e6 + 5, inf = 0x3f3f3f3f3f3f3f3f;
int c, n, k, fa[N], dep[N], f[N][30]; std::vector< int > g[N];
int F(int u) { return u == fa[u] ? u : fa[u] = F(fa[u]); }
void dfs(int u, int p) {
	f[u][0] = p, dep[u] = dep[p] + 1;
	for (int k = 1; k <= 25; ++k) f[u][k] = f[f[u][k - 1]][k - 1];
	for (auto v : g[u]) if (v != p) dfs(v, u);
} int lca(int u, int v) {
	if (dep[u] < dep[v]) std::swap(u, v);
	int x = dep[u] - dep[v];
	for (int k = 0; k <= 25; ++k) if ((1 << k) & x) u = f[u][k];
	if (u == v) return u;
	for (int k = 25; k >= 0; --k) if (f[u][k] != f[v][k]) u = f[u][k], v = f[v][k];
	return f[u][0]; 
} int len(int u, int v) { return dep[u] + dep[v] - 2 * dep[lca(u, v)]; }
signed main() {
	freopen("hub.in", "r", stdin), freopen("hub.out", "w", stdout);
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	int T; std::cin >> c >> T; while (T--) {
		std::cin >> n >> k;
		for (int i = 1; i <= n; ++i) g[i].clear();
		for (int i = 1, u, v; i < n; ++i) {
			std::cin >> u >> v;
			g[u].push_back(v), g[v].push_back(u);
		} dfs(1, 0);
		if (c <= 3) {
			int mn = inf;
			for (int sta = 0; sta < (1 << n); ++sta) {
				std::set< int > C;
				for (int i = 1; i <= n; ++i) if (sta & (1 << i - 1)) C.insert(i);
//				std::cout << ":\n";
				if (C.size() != k) continue;
				for (int i = 1; i <= n; ++i) fa[i] = i;
				for (auto x : C) for (auto y : g[x]) if (C.count(y)) fa[F(x)] = F(y);
				int cnt = 0;
				for (auto i : C) if (fa[i] == i) cnt++;
				if (cnt > 2) continue;
				int mx = 0;
				for (int i = 1; i <= n; ++i) if (!C.count(i)) {
					int mn = inf;
					for (auto j : C) mn = std::min(mn, len(i, j));
					mx = std::max(mx, mn);
				}
//				for (auto i : C) for (int j = 1; j <= n; ++j) if (!C.count(j)) mx = std::max(mx, len(i, j));
//				std::cout << mx << "\n";
				mn = std::min(mn, mx);
			}
			std::cout << mn << "\n";
		}
	}
	return 0;
}
/*
怎么是连通块问题不是路径问题啊好难受 /ll。

两个连通块的条件看起来就很复杂且棘手，考虑只有一个连通块的情况。 
最大值最小，怎么也该拼一个二分上去。
当前二分的通勤半径为 x。一个深度不大于 x 的子树，最多只需在根节点选到即可。 
所以说我们只需要找到所有深度大于等于 x 的子树，将它们的根节点选上即可。
好像还得换个根。 

接下来考虑两个连通块，这个一看就不好做嘛。 

不管了，看看特殊性质：
---
暴力：目前只会 O(n * 2^n) 的至尊暴力啊。
---
k <= 2：这个在 n<=1000 的时候可以看作是第一种至尊暴力。
若 n<=100000，猜一个直径端点的结论吧，看看是不是对的…
哦显然不对，一条链就可以 hack 掉。 

哎哎想不出来，先把至尊暴力打了吧。 
*/

