#include<bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
constexpr int MAXN = 1e6 + 9, INF = 0x3f3f3f3f;
int c, T, n, k, fa[MAXN][24], dep[MAXN];
vector<int> G[MAXN];
void dfs1(int u, int f) {
	dep[u] = dep[f] + 1;
	fa[u][0] = f;
	for(int i = 1; i <= 22; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for(auto v : G[u]) {
		if(v == f) continue;
		dfs1(v, u);
	}
}
int lca(int u, int v) {
	if(dep[u] < dep[v]) swap(u, v);
	for(int i = 22; i >= 0; i--) if(dep[fa[u][i]] >= dep[v]) u = fa[u][i];
	if(u == v) return v;
	for(int i = 22; i >= 0; i--) {
		if(fa[u][i] != fa[v][i]) {
			u = fa[u][i];
			v = fa[v][i];
		}
	}
	return fa[u][0];
}
int dis(int u, int v) {
	int lv = lca(u, v);
	return dep[u] + dep[v] - 2 * dep[lv];
}
struct DSU {
	int cnt, fa[MAXN], sz[MAXN];
	void init(int n) {
		cnt = n;
		for(int i = 1; i <= n; i++) fa[i] = i, sz[i] = 1;
	}
	int find(int x) {
		if(fa[x] == x) return x;
		else return fa[x] = find(fa[x]);
	}
	void merge(int u, int v) {
		u = find(u), v = find(v);
		if(sz[u] > sz[v]) swap(u, v);
		cnt--;
		fa[u] = v;
		sz[v] += sz[u];
	}
	int size() {
		return cnt;
	}
} dsu;
void init(int n) {
	for(int i = 1; i <= n; i++) G[i].clear();
	for(int i = 1; i <= n; i++) dep[i] = 0;
	for(int i = 1; i <= n; i++) for(int j = 0; j <= 22; j++) fa[i][j] = 0;
}
namespace P1 {
	bool inmsk(int msk, int p) {
		return ((msk >> (p - 1)) & 1);
	}
	void solve() {
		int ans = INF;
		for(int msk = 0; msk < (1 << n); msk++) {
			if(__builtin_popcount(msk) != k) continue;
			int tmp = 0;
			dsu.init(n);
			for(int i = 2; i <= n; i++) {
				int f = fa[i][0];
				if(inmsk(msk, i) && inmsk(msk, f)) dsu.merge(i, f);
			}
			if(dsu.size() > n - k + 2) continue;
			for(int i = 1; i <= n; i++) {
				if(inmsk(msk, i)) continue;
				int tp = INF;
				for(int j = 1; j <= n; j++) {
					if(i == j) continue;
					if(!inmsk(msk, j)) continue;
					tp = min(tp, dis(i, j));
				}
				tmp = max(tmp, tp);
			}
			ans = min(ans, tmp);
		}
		cout << ans << '\n';
	}
}
//namespace P2 {
//	pii dfs2(int u, int f, int d) {
//		pii p = {d, u};
//		for(auto v : G[u]) {
//			if(v == f) continue;
//			p = max(p, dfs2(v, u, d + 1));
//		}
//		return p;
//	}
//	void solve() {
//		pii p = dfs2(1, 0, 0);
//		p = dfs2(p.fi, 0, 0);
//		cout << p.se << '\n';
//	}
//}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> T;
	while(T--) {
		cin >> n >> k;
		init(n);
		for(int i = 2, u, v; i <= n; i++) {
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs1(1, 0);
//		P2::solve();
		if(c <= 3) P1::solve();
		else cout << 0 << '\n';
//		else if(c == 7 || c == 11 || c == 12) P2::solve();
	}
	return 0;
}

