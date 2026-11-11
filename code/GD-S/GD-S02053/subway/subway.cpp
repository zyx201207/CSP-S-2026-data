#include <bits/stdc++.h> 

#define FstIO ios::sync_with_stdio(0) 
#define pii pair <ll, ll> 
#define pb push_back 
#define pbk pop_back 
#define fi first 
#define se second 

using namespace std; 
using ll = long long; 
using ld = long double; 
using ull = unsigned long long; 

const ll N = 1e6 + 5, M = 600; 
const ld eps = 1e-6; 
const ll mod = 998244353, inf = 1e18; 

ll c, n, m, d, q; 
ll w[N], ln[M]; 
ll f[M][M]; 

vector <pii> li[M], h[N]; 
void add(ll x, ll y, ll c) {
	f[x][y] = f[y][x] = min(f[x][y], c); 
}
/*
f[i][j] 表示线路 i -> j 的最短路 
floyd  

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3


*/

signed main() {
	freopen("subway.in", "r", stdin); 
	freopen("subway.out", "w", stdout); 
	
	FstIO; 
	
	cin >> c >> n >> m >> d >> q; 
	for (ll i = 1; i <= n; ++ i ) 
		for (ll j = 1; j <= n; ++ j ) 
			f[i][j] = inf; 
	for (ll i = 1; i <= m; ++ i ) cin >> w[i]; 
	for (ll i = 1; i <= n; ++ i ) {
		cin >> ln[i]; 
		for (ll j = 1; j <= ln[i]; ++ j ) {
			ll a, t; cin >> a >> t; 
			h[a].pb({i, t}); li[i].pb({a, t}); 
		}
	}
	for (ll i = 1; i <= n; ++ i ) {
		for (auto x : li[i]) {
			for (auto y : h[x.fi]) {
				if (y.fi == i) continue; 
				add(i, y.fi, y.se + x.se); 
			}
		}
	}
	for (ll i = 1; i <= n; ++ i ) 
		f[i][i] = 0; 
	for (ll k = 1; k <= n; ++ k ) {
		for (ll i = 1; i <= n; ++ i ) {
			for (ll j = 1; j <= n; ++ j ) {
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]); 
			}
		}
	}
//	for (ll i = 1; i <= n; ++ i ) 
//		for (ll j = 1; j <= n; ++ j ) 
//			cout << i << ' ' << j << ' ' << f[i][j] << '\n'; 
//	cout << "-----------\n";  
	for (ll _ = 1; _ <= q; ++ _ ) {
		ll x, y; cin >> x >> y; 
		ll ans = inf; 
		for (auto a : h[x]) 
			for (auto b : h[y]) 
				ans = min(ans, a.se + b.se + f[a.fi][b.fi]); 
		ans += w[x] + w[y]; 
		cout << ans << '\n'; 
	}
	
	return 0; 
}
