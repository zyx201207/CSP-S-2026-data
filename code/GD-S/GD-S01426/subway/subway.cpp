#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<queue>
using namespace std;
using ll = long long;
const ll N = 5e5 + 3;
const ll INF = 1e17;
ll n, m, d, q;
ll w[N];
vector<pair<ll, ll>> e[N];
pair<ll, ll> f[N];
ll cnt = 0;
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> dq;
ll dij(ll x, ll y) {
	dq.push({0, x});
	f[x] = {++cnt, 0};
	while (!dq.empty()) {
		auto s = dq.top();
		dq.pop();
		ll u = s.second, d = s.first;
		if (f[u].second != d && f[u].first == cnt) continue;
		for (auto s2 : e[u]) {
			ll v = s2.first, w = s2.second;
			if (f[v].first != cnt) f[v].second = INF, f[v].first = cnt;
			if (d + w < f[v].second) {
				f[v].second = d + w;
				dq.push({f[v].second, v});
			}
		}
	}
	return f[y].second;
}
void solve() {
	cin >> n;
	cin >> n >> m >> d >> q;
	for (ll i = 1;i <= m;++i) cin >> w[i];
	for (ll i = 1;i <= n;++i) {
		ll k;cin >> k;
		for (ll j = 1;j <= k;++j) {
			ll a, t;cin >> a >> t;
			e[a].emplace_back(i + m, t);
			e[i + m].emplace_back(a, t);
		}
	}
	while (q--) {
		ll u, v;cin >> u >> v;
		cout << dij(u, v) + w[u] + w[v] << '\n';			
	}
	return;
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll _ = 1;
//	cin >> _;
	while (_--) {
		solve();
	}
}

