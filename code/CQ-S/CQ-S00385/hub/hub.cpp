#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll N = 1e6 + 5;
ll c, t;
ll n, k;
vector <ll> g[N];
bool vis[N];
ll fa[N];
bool vv[N];
ll u[N], v[N];
ll Find(ll x) {
	if (x == fa[x]) return x;
	else return fa[x] = Find(fa[x]);
}
void Merge(ll x, ll y) {
	x = Find(x), y = Find(y);
	if (x == y) return;
	fa[y] = x;
} 
ll st[35][N];
ll dep[N];
void dfs_(ll u, ll fa, ll deep) {
	st[0][u] = fa;
	dep[u] = deep;
	for (ll v : g[u]) {
		if (v == fa) continue;
		dfs_(v, u, deep + 1);
	}
}
void init() {
	for (ll i = 1; i <= 30; i++) {
		for (ll j = 1; j <= n; j++) {
			st[i][j] = st[i - 1][st[i - 1][j]];
		}
	}
}
ll LCA(ll x, ll y) {
	if (dep[x] < dep[y]) swap(x, y);
	ll ans = 0;
	for (ll i = 30; i >= 0; i--) {
		if (dep[st[i][x]] >= dep[y]) ans += (1 << i), x = st[i][x];
	}
	if (x == y) return ans;
	for (ll i = 30; i >= 0; i--) {
		if (st[i][x] != st[i][y]) ans += 2 * (1 << i), x = st[i][x], y = st[i][y];
	} 
	return ans + 2;
}
ll ans = 0x3f3f3f3f3f3f3f3f;
void dfs(ll x) {
	if (x > n) {
		ll sum = 0;
		for (ll i = 1; i <= n; i++) sum += vis[i];
		if (sum != k) return;
		memset(vv, 0, sizeof(vv));
		for (ll i = 1; i <= n; i++) fa[i] = i;
		for (ll i = 2; i <= n; i++) {
			if (vis[u[i]] && vis[v[i]]) Merge(u[i], v[i]); 
		}
		sum = 0;
		for (ll i = 1; i <= n; i++) {
			if (vis[i]) {
				ll ff = Find(i);
				sum += !vv[ff];
				vv[ff] = 1;
			}
		}
		if (sum > 2) return;
		ll res = 0;
		for (ll i = 1; i <= n; i++) {
			ll mn = 0x3f3f3f3f3f3f3f3f;
			for (ll j = 1; j <= n; j++) {
				if (vis[j]) {
					mn = min(mn, LCA(i, j));
				}
			}
			res = max(res, mn);
		}
		ans = min(ans, res);
		return;
	}
	vis[x] = 1;
	dfs(x + 1);
	vis[x] = 0;
	dfs(x + 1);
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		for (ll i = 1; i <= n; i++) g[i].clear();
		for (ll i = 2; i <= n; i++) {
			cin >> u[i] >> v[i];
			g[u[i]].push_back(v[i]);
			g[v[i]].push_back(u[i]);
		}
		ans = 0x3f3f3f3f3f3f3f3f;
		memset(vis, 0, sizeof(vis));
		memset(dep, 0, sizeof(dep));
		memset(st, 0, sizeof(st));
		dfs_(1, 0, 1);
		init();
		dfs(1);
		cout << ans << "\n";
	}
	return 0;
}
