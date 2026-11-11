#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 2e6 + 10, INF = 0x3f3f3f3f3f3f3f3f;
ll n, d, x[N], tot = 0, dis[N], cnt[N];
pair<ll, ll> qj[N];

void dij(ll s, ll t) {
	priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > pq;
	for(ll i = s; i <= t; i++) dis[i] = INF, cnt[i] = 0;
	dis[s] = 0, cnt[s] = 1, pq.push(make_pair(dis[s], s));
	while(!pq.empty()) {
		pair<ll, ll> p = pq.top(); pq.pop();
		ll u = p.second;
		for(ll k = u + 1; k <= t; k++) {
			if(x[k] - x[u] > d) break;
			if(dis[k] > dis[u] + 1) {
				dis[k] = dis[u] + 1, cnt[k] = 1;
				pq.push(make_pair(dis[k], k));
			}
			else if(dis[k] == dis[u] + 1) ++cnt[k], pq.push(make_pair(dis[k], k));
		}
	}
}

void solve() {
	tot = 0;
	cin >> n >> d;
	for(ll i = 1; i <= n; i++) cin >> x[i];
	ll l = 1;
	for(ll i = 2; i <= n; i++) {
		if(x[i] - x[i - 1] > d) {
			qj[++tot] = make_pair(l, i - 1);
			l = i;
		}
	}
	qj[++tot] = make_pair(l, n);
	ll ans = 0;
	for(ll i = 1; i <= tot; i++) {
		for(ll j = qj[i].first; j <= qj[i].second; j++) {
			dij(j, qj[i].second);
			for(ll k = j + 1; k <= qj[i].second; k++) {
//				cerr << ans << ' ' << i << ' ' << j << ' ' << k << ' ' << dis[k] << ' ' << cnt[k] << '\n'; 
				if(cnt[k] == 2) ++ans;
			}
		}
	} 
	cout << ans << '\n';
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ll c, t; cin >> c >> t;
	while(t--) solve();
	return 0;
}
/*
0 1
10 3
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983
*/
/*
0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
*/
