#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll w[1000005];
vector<pair<ll, ll> > v[1000005];
ll mz[1000005];
ll ans = 1e18;
bool val[1000005];
void dfs(ll x, ll y, ll sum) {
	if (x == y) {
		ans = min(ans, sum);
		return;
	}

	sum += mz[x];
	for (int i = 0; i < v[x].size(); i++) {
		if (!val[v[x][i].first] && v[x][i].first!=x) {
			val[v[x][i].first] = true;
			dfs(v[x][i].first, y, sum + v[x][i].second);
			val[v[x][i].first] = false;
		}	
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c;
	ll n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (ll i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (ll i = 1; i <= n; i++) {
		ll k = 0;
		cin >> k;	
		for (ll j = 1; j <= k; j++) {
			ll x, w;
			cin >> x >> w;
			if (x == i) {
				mz[i] = w;
			}
			v[i].push_back({x, w});
			v[x].push_back({i, w});
		}
	}
	while (q--) {
		ll x, y;
		cin >> x >> y;
		ans = 1e18;
		val[x]=true;
		dfs(x, y, 0);
		val[x]=false;
		cout << ans+w[x]+w[y] << endl;
	}
	return 0;
}
