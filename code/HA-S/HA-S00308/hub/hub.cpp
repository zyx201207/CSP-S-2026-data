#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1000010;
vector<ll> g[N];
bool vis[N];
ll d(ll i, ll u) {
	if ((i >> (u - 1)) & 1) return 0;
	vis[u] = true;
	ll res = LLONG_MAX - 1;
	for (ll j = 0; j < g[u].size(); j++) {
		ll v = g[u][j];
		if (vis[v]) continue;
		res = min(res, d(i, v) + 1);
	}
	vis[u] = false;
	return res;
}
void dfs(ll i, ll u) {
	vis[u] = true;
	for (ll j = 0; j < g[u].size(); j++) {
		ll v = g[u][j];
		if (!vis[v] && ((i >> (v - 1)) & 1)) {
			dfs(i, v);
		}
	}
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll c, t;
	cin >> c >> t;
	while (t--) {
		ll n, k;
		cin >> n >> k;
		for (ll i = 1; i <= n; i++) {
			g[i].clear();
		}
		for (ll i = 1; i <= n - 1; i++) {
			ll u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if (1 <= c && c <= 3) {
			ll ans = LLONG_MAX;
			for (ll i = 0; i < (1 << n); i++) {
				ll cnt = 0;
				for (ll j = 0; j < n; j++) {
					if ((i >> j) & 1) {
						cnt++;
					}
				}
				if (cnt != k) continue;
				cnt = 0;
				for (ll j = 1; j <= n; j++) {
					if (((i >> (j - 1)) & 1) && !vis[j]) {
						cnt++;
						dfs(i, j);
					}
				}
				for (ll i = 1; i <= n; i++) vis[i] = false;
				if (cnt > 2) continue;
				ll res = 0;
				for (ll j = 1; j <= n; j++) {
					res = max(res, d(i, j));
				}
				ans = min(ans, res);
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
