#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
constexpr int maxn = 1e6 + 10;
vector <int> e[maxn]; int f[maxn];
int n, k, fa[maxn], vis[maxn], ans;
int find (int x) {
	if (x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}
void merge (int a, int b) {
	a = find(a), b = find(b);
	if (a == b) return;
	fa[a] = b;
}
void DP (int u, int _fa) {
	f[u] = 1e9;
	for (int v : e[u]) {
		if (v == _fa) continue;
		DP(v, u);
		f[u] = min(f[u], f[v] + 1);
	}
	if (vis[u] == 1) f[u] = 0;
}
void dfs (int now, int ch) {
	// 当前需要判断 now 选不选, 前面选了 ch 个了
	if ((n - now + 1) + ch < k) return;
	if (ch > k) return;
	if (now == n + 1) {
		for (int u = 1; u <= n; u ++) fa[u] = u;
		for (int u = 1; u <= n; u ++)
			for (int v : e[u]) {
				if (vis[u] == 1 && vis[v] == 1)
					merge(u, v);
			}
		int CNT = 0;
		for (int i = 1; i <= n; i ++) {
			if (vis[i] == 1 && find(i) == i) CNT ++;
		}
		if (CNT > 2) return;
		int Mx = 0;
		for (int rt = 1; rt <= n; rt ++) {
			DP(rt, 0);
			Mx = max(Mx, f[rt]);
		}
		ans = min(ans, Mx);
	}
	dfs(now + 1, ch); vis[now] = 1; dfs(now + 1, ch + 1); vis[now] = 0;
}
signed main () {
//	freopen("hub2.in", "r", stdin);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	int c, tid; cin >> c >> tid;
	while (tid --) {
		cin >> n >> k; ans = n;
		for (int i = 1; i <= n; i ++) vis[i] = 0, fa[i] = i, e[i].resize(0);
		for (int i = 1; i < n; i ++) {
			int u, v; cin >> u >> v;
			e[u].push_back(v), e[v].push_back(u);
		} dfs(1, 0); cout << ans << '\n'; 
	}
}
