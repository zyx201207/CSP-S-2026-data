#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll M = 5e5 + 10, N = 5e3 + 10;
ll c, n, m, d, q;
ll W[M];
vector<pair<ll, ll>> g[N];
ll dis[510];

void dfs(ll way) {
//	if(dis[sta][way] == 0x3f3f3f3f3f3f3f3f) return;
//	cout << sta << ' ' << way << '\n';
//	ll pos = upper_bound(g[way].begin(), g[way].end(), pair<ll, ll>{sta, 0}) - g[way].begin();
////	cout << way << ':' << sta << '-' << pos << '\n';
//	if(pos < g[way].size() - 1) {
//		ll nxt = g[way][pos + 1].first;
////		cout << "->" << nxt << '\n';
//		if(dis[way] > dis[way]) {
//			dis[way] = dis[way];
//			dfs(nxt, way);
//		}
//	}
for(ll i = 1; i <= n; i ++){
	for(ll j = 0; j <= g[way].size(); j ++) {
		ll pos_ = upper_bound(g[i].begin(), g[i].end(), pair<ll, ll>{j, 0}) - g[i].begin();
		if(g[i][pos_].first == j) {
//			cout << i << ':' <<  sta << '-' << pos_ << '\n';
			if(dis[i] > dis[way] + g[way][j].second + g[i][pos_].second) {
				dis[i] = dis[way] + g[way][j].second + g[i][pos_].second;
//				cout << dis[sta][way] + g[way][pos].second + g[i][pos_].second << ' '; 
//				cout << dis[sta][i];
//				cout << "HHHHHHHHHHHHH";
				dfs(i);
			}
		}
	}
}
}

void solve() {
	cin >> c >> n >> m >> d >> q;
	for(ll i = 1; i <= m; i ++) {
		cin >> W[i];
	}
	for(ll i = 1; i <= n; i ++) {
		ll k; cin >> k;
		for(ll j = 1; j <= k; j ++) {
			ll a, t; cin >> a >> t;
			g[i].push_back({a, t});
		}
	}
		while(q --) {
			memset(dis, 0x3f, sizeof dis);
			ll x, y; cin >> x >> y;
			ll ans = 1e18;
			for(ll i = 1; i <= n; i ++) {
				ll p = upper_bound(g[i].begin(), g[i].end(), pair<ll, ll>{y, 0}) - g[i].begin();
				if(g[i][p].first == x){
					dis[i] = W[x] + g[i][p].second;
					dfs(i);
				}
				
			}
//			for(ll i = 1; i <= n; i ++) {
//				cout << dis[i] << '\n';
//			}
			for(ll i = 1; i <= n; i ++) {
				ll p = upper_bound(g[i].begin(), g[i].end(), pair<ll, ll>{y, 0}) - g[i].begin();
				if(g[i][p].first == y){
					ans = min(ans, dis[i] + g[i][p].second);
				}
			}
			cout << ans + W[y] << '\n';
		}
	return;
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	solve();
	
	return 0;
}
