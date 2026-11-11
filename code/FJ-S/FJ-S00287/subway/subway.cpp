#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3f;
ll c, n, m, d, q, dis[502][502], w[500002];
vector<pair<ll, ll> > t[500002];
void chm(ll &x, ll y) {
	x = min(x, y);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (ll i = 1; i <= m; i ++ ) cin >> w[i];
	for (ll i = 1, k; i <= n; i ++ ) {
		cin >> k;
		for (ll x, y; k --; ) cin >> x >> y, t[x].push_back({i, y});
	}
	for (ll i = 1; i <= n; i ++ ) for (ll j = 1; j < i; j ++ ) dis[i][j] = dis[j][i] = inf;
	// 1. O(md^2)
	for (ll i = 1; i <= m; i ++ ) for (pair<ll, ll> x : t[i]) for (pair<ll, ll> y : t[i])
		chm(dis[x.first][y.first], x.second + y.second);
	// 2. O(n^3)
	for (ll k = 1; k <= n; k ++ ) for (ll i = 1; i <= n; i ++ ) for (ll j = 1; j <= n; j ++ )
		chm(dis[i][j], dis[i][k] + dis[k][j]);
	// 3. O(qd^2)
	for (ll x, y, res = inf; q --; ) {
		cin >> x >> y; res = inf;
		for (pair<ll, ll> u : t[x]) for (pair<ll, ll> v : t[y]) 
			res = min(res, dis[u.first][v.first] + u.second + v.second);
		cout << res + w[x] + w[y] << "\n";
	}
}
//15.15
