#include <bits/stdc++.h>
#define fi first
#define se second
#define IOS ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;
using LL = long long;
using pii = pair<int, int>;

constexpr int MAXN = 4e3, MAXM = 2e6, mod = 998244353;
inline void chmax(int &x, int val) { if (x < val) x = val; }
inline void chmin(int &x, int val) { if (x > val) x = val; }
inline void inc(int &x, int val) { (x += val) >= mod && (x -= mod); }
inline void dec(int &x, int val) { (x -= val) < 0 && (x += mod); }
inline void tim(int &x, int val) { (x *= val) %= mod; }

inline int qpow(int x, int y = mod - 2) {
	int res = 1;
	while (y) {
		if (y & 1) tim(res, x);
		tim(x, x), y >>= 1;
	}
	return res;	
}

int C, T, n, m, cur, rt, fa[MAXN+5], dep[MAXN+5], top[MAXN+5], son[MAXN+5], siz[MAXN+5], len[MAXN+5], f[MAXN+5][MAXN+5];
int dfn[MAXN+5], rk[MAXN+5], tmp[MAXN+5];
vector<int> G[MAXN+5];
inline void prework(int u, int f = 0) {
	fa[u] = f, dep[u] = dep[f] + 1, siz[u] = 1, son[u] = 0;
	for (int v : G[u]) {
		if (v == f) continue;
		prework(v, u);
		if (siz[son[u]] < siz[v]) son[u] = v;
		siz[u] += siz[v];
	}
}
inline void Get_Top(int u, int cur) {
	top[u] = cur;
	if (son[u]) Get_Top(son[u], cur);
	for (int v : G[u]) 
		if (v != fa[u] && v != son[u]) Get_Top(v, v);
}
inline int lca(int x, int y) {
	while (top[x] ^ top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		x = fa[top[x]];
	}
	return dep[x] < dep[y] ? x : y;
}
inline int dist(int x, int y) { return dep[x] + dep[y] - (dep[lca(x, y)] << 1); }
inline void dfs1(int u) {
	siz[u] = 1, len[u] = 0, f[u][0] = f[u][1] = 0, rk[dfn[u] = ++*dfn] = u;
	for (int v : G[u]) {
		if (v == fa[u] || v == cur) continue;
		dfs1(v);
		for (int j = 1; j <= siz[u] + siz[v]; ++j) tmp[j] = f[u][j], f[u][j] = 1e9;
		for (int i = 1; i <= siz[u]; ++i) 
			for (int j = 0; j <= siz[v] && i + j <= m; ++j) 
				chmin(f[u][i + j], max(tmp[i], f[v][j]));
		siz[u] += siz[v];
		len[u] = max(len[u], len[v] + 1);
	}
	for (int i = dfn[u]; i < dfn[u] + siz[u]; ++i) {
		chmax(f[u][0], min(dist(rk[i], u) + 1, dist(rk[i], cur)));
//		chmax(f[u][0], dist(rk[i], cur));
	}
//	if (rt == 2 && cur == 4) {
//		cout << u << " : \n";
//		for (int i = 0; i <= siz[u]; ++i) cout << f[u][i] << ' ';
//		cout << '\n';
//	}
}
inline void dfs2(int u) {
	siz[u] = 1, len[u] = 0, f[u][0] = f[u][1] = 0;
	for (int v : G[u]) {
		if (v == fa[u]) continue;
		dfs2(v);
		for (int j = 1; j <= siz[u] + siz[v]; ++j) tmp[j] = f[u][j], f[u][j] = 1e9;
		for (int i = 1; i <= siz[u]; ++i) 
			for (int j = 0; j <= siz[v] && i + j <= m; ++j) 
				chmin(f[u][i + j], max(tmp[i], f[v][j]));
		siz[u] += siz[v];
		len[u] = max(len[u], len[v] + 1);
	}
	f[u][0] = len[u] + 1;
}
inline void solve() {
	cin >> n >> m;
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		G[u].emplace_back(v), G[v].emplace_back(u);
	}
	if (C == 13 || C == 14) {
		int l = 1, r = n, ans = n;
		while (l <= r) {
			int mid = (l + r) >> 1;
			int L = mid, R = (n + 1) / 2 - mid;
			int res = R - L + 1 - (mid * 2 - 2);
			if (res <= m) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		cout << ans << '\n';
		for (int i = 1; i <= n; ++i) vector<int>().swap(G[i]);
		return;
	}
	if (C == 7) {
		prework(1), Get_Top(1, 1);
		int res = 1e9;
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				int cur = 0; 
				for (int k = 1; k <= n; ++k) {
					cur = max(cur, min(dist(i, k), dist(j, k)));
					if (res < cur) break;
				}
				res = min(res, cur);
			}
		}
		cout << res << '\n';
		for (int i = 1; i <= n; ++i) vector<int>().swap(G[i]);		
		return;
	}
	int ans = 1e9;
	for (int i = 1; i <= n; ++i) {
		rt = i, prework(i), Get_Top(i, i);
		for (cur = 1; cur <= n; ++cur) {
			if (cur == i) continue;
			dfn[0] = 0;
			dfs1(i), dfs2(cur);
			for (int j = 1; j <= min(siz[cur], m - 1); ++j) {
//					uf cout << i << ' ' << cur << " : " << f[cur][j] << ' ' << f[i][m - j] << '\n';
				chmin(ans, max(f[cur][j], f[i][m - j])); 
			}
		}
	}
	cout << ans << '\n';
	for (int i = 1; i <= n; ++i) vector<int>().swap(G[i]);
}

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	IOS;
	cin >> C >> T;
	while (T--) solve();
	return 0;
}
/*
5 2 : 1
7 2 : 2
7 3 : 1
9 2 : 2
9 3 : 2
9 4 : 1
11 2 : 2
11 3 : 2
11 4 : 2
11 5 : 1
13 2 : 2
13 3 : 2
13 4 : 2
13 5 : 2
13 6 : 1
13 7 : 1
15 2 : 3
15 3 : 2
15 4 : 2
15 5 : 2
15 6 : 2
15 7 : 1
15 8 : 1
15 9 : 1
17 2 : 3
17 3 : 3
17 4 : 2
17 5 : 2
17 6 : 2
17 7 : 2
*/
