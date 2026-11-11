#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 10;
ll c, T, n, k;
vector <pair <ll, ll> > sd;
ll dep[N], up[N][31], h[N], ff[N];
bool mk[N];
vector <ll> g[N];
void dfs (ll u, ll fa) {
	dep[u] = dep[fa] + 1;
	up[u][0] = fa;
	for (int i = 1; i < 31; ++ i) up[u][i] = up[up[u][i - 1]][i - 1];
	for (int i = 0; i < g[u].size (); ++ i) {
		ll v = g[u][i];
		if (v == fa) continue;
		dfs (v, u);
	}
}
ll lca (ll x, ll y) {
	if (dep[y] < dep[x]) swap (x, y);
	ll ds = dep[y] - dep[x];
	for (ll j = 0; ds; ++ j, ds >>= 1) if (ds & 1) 
		y = up[y][j];
	if (x == y) return x;
	for (int j = 30; j >= 0; -- j) {
		if (up[x][j] != up[y][j]) {
			x = up[x][j]; 
			y = up[y][j];
		}
	}
	return up[x][0];
}
ll find (ll x) {return (x == ff[x]) ? x : ff[x] = find (ff[x]);}
bool check (ll msk) {
	for (int i = 1; i <= n; ++ i) ff[i] = i, mk[i] = 0;
	for (int i = 1; i <= n; ++ i) {
		if (msk & (1 << (i - 1))) {
			mk[i] = 1;
		}
	} 
	for (int i = 0; i < sd.size (); ++ i) {
		ll u = sd[i].first, v = sd[i].second;
		if (mk[u] && mk[v]) {
			ll fu = find (u), fv = find (v);
			if (fu != fv) ff[fu] = fv; 
		}
	}
	vector <ll> uni;
	for (int i = 1; i <= n; ++ i) {
		if (mk[i]) uni.push_back (find (i));
	}
	sort (uni.begin (), uni.end ());
	uni.erase (unique (uni.begin (), uni.end ()), uni.end ());
	return uni.size () <= 2;
}
void solve ();
int main () {
	freopen ("hub.in", "r", stdin);
	freopen ("hub.out", "w", stdout);
	cin >> c >> T;
	while (T --) {solve ();}
	return 0;
}
void solve () {
	cin >> n >> k;
	for (int i = 1; i <= n; ++ i) {
		for (int j = 0; j < 31; ++ j) up[i][j] = 0;
		g[i].clear (); dep[i] = 0;
	}
	for (int i = 1; i < n; ++ i) {
		ll u, v; cin >> u >> v;
		g[u].push_back (v);
		g[v].push_back (u);
		sd.push_back ({u, v});
	}
	dfs (1, 0);
	ll res = 4e18;
	for (ll msk = 0; msk < (1 << n); ++ msk) {
		if (__builtin_popcount (msk) != k || check (msk) == 0) continue;
		for (int i = 1; i <= n; ++ i) h[i] = 4e18;
		for (int i = 0; i < n; ++ i) if (msk & (1 << i)) {
			ll o = i + 1; h[o] = 0;
			for (int j = 1; j <= n; ++ j) {
				if (j == o) continue;
				ll la = lca (j, o);
				h[j] = min (h[j], dep[o] + dep[j] - 2 * dep[la]);
			}
		}
		ll mx = 0; for (int i = 1; i <= n; ++ i) mx = max (mx, h[i]);
		res = min (res, mx);
	}
	cout << res << '\n';
}
