//GZ-S00062 ∏∂Í¿‘Û 
#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define vec vector
#define str string
#define fi first
#define se second
using namespace std;

const ll N = 505;
const ll M = 5e5 + 5;
const ll D = 25;
const ll Q = 1e5 + 5;

ll w[M];
struct Doc {
	ll k;
	vec<ll> a, t;
	void build() {
		a.resize(k + 1);
		t.resize(k + 1);
	}
}x[N];
pll qt[Q];

vec<pll> l[M];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	ll c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	
	for(ll i = 1;i <= m;i++)
	    cin >> w[i];
	
	for(ll i = 1;i <= n;i++) {
		cin >> x[i].k;
		x[i].build();
		for(ll j = 1;j <= x[i].k;j++) {
		    cin >> x[i].a[j] >> x[i].t[j];
		    l[x[i].a[j]].push_back({x[i].t[j], i});
		}
	}
	
	ll e[N][N];
	for(ll i = 1;i <= n;i++) {
	    fill(e[i] + 1, e[i] + n + 1, 1e18);
		e[i][i] = 0;
	}
	
	for(ll i = 1;i <= m;i++) {
		ll len = l[i].size();
		for(ll j = 0;j < len;j++) {
			ll j1 = l[i][j].fi, j2 = l[i][j].se;
			for(ll k = 0;k < len;k++) {
			    ll k1 = l[i][k].fi, k2 = l[i][k].se;
				e[j2][k2] = e[k2][j2] = min(e[j2][k2], j1 + k1);
			}
		}
	} 
	
	for(ll i = 1;i <= n;i++)
	    for(ll j = 1;j <= n;j++)
	        for(ll k = 1;k <= n;k++)
	        	e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
	
	for(ll i = 1;i <= q;i++) {
		ll ans = 1e18;
		ll u, v; cin >> u >> v;
		ll l1 = l[u].size(), l2 = l[v].size();
	    for(ll j = 0;j < l1;j++)
	        for(ll k = 0;k < l2;k++) {
	        	ll s = l[u][j].fi + l[v][k].fi;
	            ans = min(ans, e[l[u][j].se][l[v][k].se] + s);
			}
	    cout << ans + w[u] + w[v] << endl;
	}
	    
	return 0;
}
