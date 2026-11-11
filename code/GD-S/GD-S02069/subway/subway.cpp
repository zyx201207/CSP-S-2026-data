#include <iostream>
#include <ctime>
#include <cstring>
#include <queue>
#include <map>
#include <set>
using ll = long long;
using namespace std;
constexpr ll N = 500+5;
constexpr ll M = 5e5+5;
constexpr ll KSUM = 5e5+5;
constexpr ll D = 20+5;
ll w[M];
map<ll,ll> at[N];
set<ll> sts[N];
ll dis[M];

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for (ll i = 1; i <= m; ++i) cin >> w[i];
	for (ll i = 1; i <= n; ++i) {
		ll k;
		cin >> k;
		for (ll j = 1; j <= k; ++j) {
			ll a,t;
			cin >> a >> t;
			at[i][a] = t;
			sts[i].insert(a);
		}
	}
	while (q--) {
		ll x,y;
		cin >> x >> y;
		ll ans = w[x] + w[y];
		memset(dis,0,sizeof dis);
		queue<ll> qu;
		qu.push(x);
		dis[x] = 0;
		for (ll i = 1; i <= n; ++i)
		while (!qu.empty()) {
			ll f = qu.front();
			qu.pop();
			for (ll i = 1; i <= n; ++i) {
				if (!sts[i].count(f)) continue;
				for (pair<ll,ll> j : at[i]) {
					if (j.first == x) continue;
					if (j.first == f) continue;
					ll tim = at[i][f] + j.second;
					if (dis[j.first] != 0 && dis[f] + tim >= dis[j.first]) continue;
					dis[j.first] = dis[f] + tim;
					qu.push(j.first);
				}
			}
		}
		cout << ans + dis[y] << endl;
	}
	return 0;
}
