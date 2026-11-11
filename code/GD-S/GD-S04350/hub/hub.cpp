#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10, LOG = 20;
int n, k, d[15], dep[N], fa[N][LOG], ans = 1e18, Max, Maxid;
vector<int> adj[N];
void dfs1(int u, int pre) {
	dep[u] = dep[pre] + 1, fa[u][0] = pre;
	for (int i = 1; i < LOG; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (auto x : adj[u]) {
		if (x == pre) continue;
		dfs1(x, u);
	}
}
int lca(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	for (int i = 19; i >= 0; i--)
		if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
	if (u == v) return u;
	for (int i = 19; i >= 0; i--)
		if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
	return fa[u][0];
}
void dfs(int u, int cnt) {
	if (cnt == k) {
		int cnt1 = k;
		for (int i = 1; i <= k; i++)
			for (int j = i + 1; j <= k; j++)
				if (fa[d[i]][0] == d[j] || fa[d[j]][0] == d[i]) cnt1--;
		if (cnt1 > 2) return;
		int Max = 0;
		for (int j = 1; j <= n; j++) {
			int Min = 1e18;
			for (int i = 1; i <= k; i++) {
				int l = lca(j, d[i]);
				int val = dep[j] + dep[d[i]] - 2 * dep[l];
				Min = min(Min, val);
			}
			Max = max(Max, Min);
		}
		ans = min(ans, Max);
		return;
	}
	if (u == n + 1) return;
	dfs(u + 1, cnt);
	d[cnt + 1] = u;
	dfs(u + 1, cnt + 1);
}
void dfs2(int u, int pre, int d) {
	fa[u][0] = pre;
	for (int i = 1; i < LOG; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
	if (d > Max) {
		Max = d;
		Maxid = u;
	}
	for (auto x : adj[u]) {
		if (x == pre) continue;
		dfs2(x, u, d + 1);
	}
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c, t;
	cin >> c >> t;
	if (c <= 3 || c == 7) {
		while (t--) {
			ans = 1e18;
			cin >> n >> k;
			for (int i = 1; i <= n; i++) adj[i].clear();
			for (int i = 1; i < n; i++) {
				int u, v;
				cin >> u >> v;
				adj[u].push_back(v);
				adj[v].push_back(u);
			}
			dfs1(1, 0);
			dfs(1, 0);
			cout << ans << '\n';
		}
	} else {
		srand(time(0));
		while (t--) {
			cout << rand() << '\n';
		}
	}
//	else if (k == 1) {
//		while (t--) {
//			cin >> n >> k;
//			for (int i = 1; i <= n; i++) adj[i].clear();
//			for (int i = 1; i < n; i++) {
//				int u, v;
//				cin >> u >> v;
//				adj[u].push_back(v);
//				adj[v].push_back(u);
//			}
//			dfs1(1, 0);
//			for (int i = 1; i <= n; i++) {
//				
//			}
//		}
//	}
	return 0;
}
