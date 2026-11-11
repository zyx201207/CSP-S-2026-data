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

const ll N = 1e6 + 5, M = 200; 
const ld eps = 1e-6; 
const ll mod = 998244353, inf = 1e18; 

ll c, t, n, k; 
vector <ll> G[N]; 

ll fa[N]; 
bool vis[N], ok[M][M];  
ll find(ll u) {
	return fa[u] == u ? u : fa[u] = find(fa[u]); 
}
bool check() {
	for (ll i = 1; i <= n; ++ i ) fa[i] = i; 
	for (ll i = 1; i <= n; ++ i ) {
		if (!vis[i]) continue; 
		for (ll j = 1; j <= n; ++ j ) {
			if (!vis[j] || i == j) continue; 
			if (ok[i][j]) 
				fa[find(i)] = find(j); 
		}
	}
	ll res = 0; 
	for (ll i = 1; i <= n; ++ i ) {
		if (!vis[i]) continue; 
		res += (fa[i] == i); 
	}
	return (res == 2); 	
}
bool inq[N]; 
ll bfs(ll u) {
	queue <pii> q; 
	for (ll i = 1; i <= n; ++ i ) inq[i] = false; 
	q.push({u, 0}); inq[u] = true; 
	while (!q.empty()) {
		auto tp = q.front(); q.pop(); 
		if (vis[tp.fi]) 
			return tp.se; 
		for (auto x : G[tp.fi]) {
			if (!inq[x]) 
				q.push({x, tp.se + 1}), inq[x] = true; 
		}
	}
	return 114514; 
}
ll dist(ll u) {
	return bfs(u); 
}
void Subtask() {
	cin >> n >> k; 
	for (ll i = 1; i < n; ++ i ) {
		ll u, v; cin >> u >> v; 
		G[u].pb(v); G[v].pb(u); 
		ok[u][v] = ok[v][u] = true; 
	}
	ll all = 1ll << n, ans = inf; 
	for (ll ms = 0; ms < all; ++ ms ) {
		if (__builtin_popcount(ms) != k) continue; 
		for (ll i = 1; i <= n; ++ i ) {
			vis[i] = ms >> (i - 1) & 1; 
		}
		if (!check()) continue; 
//		cout << "pt: ";  
//		for (ll i = 1; i <= n; ++ i ) {
//			if (vis[i]) 
//				cout << i << ' '; 
//		}
//		cout << '\n'; 
		
		ll res = 0; 
		for (ll i = 1; i <= n; ++ i ) {
//			cout << i << ' ' << dist(i) << '\n'; 
			res = max(res, dist(i)) ; 
		}	
		ans = min(ans, res); 
	}
	cout << ans << '\n'; 
	for (ll i = 1; i <= n; ++ i ) {
		G[i].clear(); 
		for (ll j = 1; j <= n; ++ j ) 
			ok[i][j] = false; 
	}
		
}

/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10


0 1 
5 2
1 2
2 3
3 4
4 5

0 1
7 2
1 2
2 3
3 4
1 5
2 6
3 7
*/

signed main() {
	freopen("hub.in", "r", stdin); 
	freopen("hub.out", "w", stdout); 
	
	FstIO; 
	
	cin >> c >> t; 
	for (ll _ = 1; _ <= t; ++ _ ) {
		Subtask(); 
	}
	
	return 0; 
}
