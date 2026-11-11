#include <bits/stdc++.h>

#define int long long

using namespace std;

namespace zcq_qwq {
	const int N = 1e6 + 5;
	
	int c, t, n, k;
	
	vector<int> G[N];
	
	int dep[N], st[N][21], fa[N];
	
	bool vis[N];
	
	void dfs(int u, int fa) {
		dep[u] = dep[fa] + 1;
		st[u][0] = fa;
		for (int i = 1; i <= 20; i++) st[u][i] = st[st[u][i - 1]][i - 1];
		for (auto i : G[u]) {
			if (i == fa) continue;
			dfs(i, u);
		}
	}
	
	int LCA(int u, int v) {
		if (dep[u] < dep[v]) swap(u, v);
		for (int i = 20; i >= 0; i--) {
			if (dep[st[u][i]] >= dep[v]) u = st[u][i];
		}
		if (u == v) return u;
		for (int i = 20; i >= 0; i--) {
			if (st[u][i] != st[v][i]) u = st[u][i], v = st[v][i];
		}
		return st[u][0];
	}
	
	int ask(int x) {
		int ans = 0;
		for (int i = 30; i >= 0; i--) {
			ans += (x >> i & 1);
		} 
		return ans;
	}
	
	int dist(int u, int v) {
		return dep[u] + dep[v] - 2 * dep[LCA(u, v)];
	}
	
	int find(int x) {
		return (fa[x] == x ? x : fa[x] = find(fa[x]));
	}
	
	void solve() {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) G[i].clear();
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1, 0);
		int ans = 0x3f3f3f3f;
		for (int i = 1; i < (1 << n); i++) {
			if (ask(i) != k) continue;
			vector<int> node;
			for (int j = 1; j <= n; j++) fa[j] = j, vis[j] = false;
			for (int j = 1; j <= n; j++) {
				if ((i >> j - 1) & 1) {
					node.push_back(j);
					vis[j] = true;
				}
			}
			int cnt = node.size();
			for (auto j : node) {
				for (auto k : G[j]) {
					if (vis[k]) {
						int x = find(j), y = find(k);
						if (x != y) {
							fa[x] = y;
							cnt--;
						}
					}
				}
			}
			if (cnt > 2) continue;
			int mx = 0;
			for (int j = 1; j <= n; j++) {
				int mn = 0x3f3f3f3f;
				for (auto k : node) {
					mn = min(mn, dist(j, k));
				}
				mx = max(mx, mn);
			}
			ans = min(ans, mx);
		}
		cout << ans << '\n';
	} 
	
	void main() {
		cin >> c >> t;
		while (t--) {
			solve();
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	zcq_qwq::main();
	return 0;
}

/*
最大值最小，是经典二分
就是想如何 check。
目标是拿到 40pts
那么我们n^2 check 就行了
我们可以dfs n 次，然后每次都把距离 <= mid 的选了
但是要恰好 k 个，还要不能超过两个连通块


0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
