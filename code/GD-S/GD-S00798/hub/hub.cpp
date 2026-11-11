#include <bits/stdc++.h>
#define int long long
using namespace std;
int c, t;
int n, k;
vector <int> G[4010], tr[4010];
int maxd, disc, dep[4010], h[4010], fa[4010];
void make_tr(int u = 1, int f = 0) {
	tr[f].emplace_back(u);
	fa[u] = f;
	for (int v: G[u]) if (v != f) make_tr(v, u);
}
void init(int u) {
	for (int v: tr[u]) {
		if (v == disc) continue;
		dep[v] = dep[u] + 1;
		init(v);
		h[u] = max(h[u], h[v] + 1);
	}
}
int dfs(int u) { 
	if (h[u] < maxd) return 0;
	int res = 1;
	for (int v: tr[u]) {
		if (v == disc) continue;
		res += dfs(v);
	}
	return res;
}
int calc(int u) {
	memset(dep, 0, sizeof(dep));
	memset(h, 0, sizeof(h));
	init(u);
	int cent = u;
	for (int i = 1; i <= n; i++) if (dep[cent] < dep[i]) cent = i;
	for (int i = 1; i <= maxd; i++) cent = fa[cent];
	if (!cent || cent == u) return 1;
	
	int ff = cent;
	vector <int> vec;
	while (ff) vec.emplace_back(ff), ff = fa[ff];
	reverse(vec.begin(), vec.end());
	
	int res = 1;
	while (fa[cent]) {
		res++;
		int f = fa[cent];
		for (int v: tr[f]) {
			if (v == disc || v == cent) continue;
			res += dfs(v);
		}
		cent = fa[cent];
	}
	int mxv = -1;
	for (int i = 0; i < vec.size() - 1; i++) {
		int cc = vec[i];
		mxv++;
		for (int v: tr[cc]) {
			if (v == disc || v == vec[i + 1]) continue;
			mxv = max(mxv, h[v] + 2);
		}
		if (mxv > maxd) break;
		res--;
	}
	return res;
}
bool check() {
	for (disc = 2; disc <= n; disc++) if (calc(1) + calc(disc) <= k) return true;
	return false;
}
void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) G[i].clear(), tr[i].clear();
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	make_tr();
	int L = 0, R = n;
	while (L < R) {
		maxd = (L + R) >> 1;
		if (check()) R = maxd;
		else L = maxd + 1;
	}
	cout << L << '\n';
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> c >> t;
	while (t--) solve();
	return 0;
}
