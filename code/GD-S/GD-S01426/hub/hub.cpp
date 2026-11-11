#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;
using ll = long long;
const ll N = 1e6 + 3;
ll n, vis[N], vis2[N], k;
vector<ll> e[N];
ll f[N];
void dfs(ll u, ll fa) {
	if (vis[u] || (!vis2[u])) return;
	for (ll v : e[u]) {
		if (v == fa) continue;
		vis[v] = 1;
		dfs(v, u);
	}
}
void solve() {
	cin >> n >> k;
	for (ll i = 1;i <= n;++i) e[i].clear();
	for (ll i = 1;i < n;++i) {
		ll u, v;cin >> u >> v;
		e[u].emplace_back(v);
		e[v].emplace_back(u);
	}
	ll m = (1 << n);
	vector<ll> a;
	ll ans = 1e7;
	for (ll ms = 0;ms < m;++ms) {
		ll res = 0;
		a.clear();
		for (ll i = 1;i <= n;++i) vis2[i] = 0, f[i] = 1e7;
		for (ll i = 0;i < n;++i) {
			if ((ms >> i) & 1) a.emplace_back(i + 1), res++, vis2[i + 1] = 1;
			vis[i + 1] = 0;
		}
		if (res != k) continue;
		ll cnt = 0;
		for (ll u : a) {
			if (!vis[u]) cnt++, dfs(u, 0);
		}
		if (cnt > 2) continue;
		queue<pair<ll, ll>> q;
		res = 0;
		for (ll u : a) q.push({u, 0}), f[u] = 0;
		while (!q.empty()) {
			ll u = q.front().first, d = q.front().second;
			q.pop();
			if (d != f[u]) continue;
			for (ll v : e[u]) {
				if (d + 1 < f[v]) {
					f[v] = d + 1;
					q.push({v, f[v]});
				}
			}
		}
		for (ll i = 1;i <= n;++i) {
			res = max(res, f[i]);
		}
		ans = min(ans, res);
	}
	if (ans == 1e7) cout << "1\n";
	else cout << ans << '\n';
	return;
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll _ = 1;
	cin >> _ >> _;
	while (_--) {
		solve();
	}
}

