#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
vector<pair<int, int>> E[505], V[N];
vector<pair<ll, ll> > G[505];
bool vis[N], viss[505][505];
ll a[505][505], dis[505][505], w[N];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	freopen("subway.in", "r", stdin);
//	freopen("subway.out", "w", stdout); 
	ll c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++ ) cin >> w[i];
	for(int i = 1; i <= n; i ++ ) {
		int k;
		cin >> k;
		for(int j = 1; j <= k; j ++ ) {
			int v, w;
			cin >> v >> w;
			E[i].push_back({w, v});
			V[v].push_back({w, i});
		}
	} 
	memset(a, 0x3f, sizeof a);
	ll maxx = a[1][1];
	for(int i = 1; i <= n; i ++ ) {
		for(auto x : E[i]) {
			ll v = x.second, w = x.first;
			if(vis[v]) continue ;
			vis[v] = 1;
			for(auto ls : V[v]) {
				ll xv = ls.second, xw = ls.first;
				if(xv == i) continue ;
				a[xv][i] = a[i][xv] = min(a[i][xv], w + xw);
			}
		}
	}
	for(int i = 1; i <= n; i ++ ) {
		for(int j = 1; j <= n; j ++ ) {
			if(i == j) continue ;
			if(a[i][j] != maxx) G[i].push_back({a[i][j], j}); //w, v 
		}
	}
	memset(dis, 0x3f, sizeof dis);
	for(int i = 1; i <= n; i ++ ) dis[i][i] = 0;
	for(int i = 1; i <= n; i ++ ) {
		priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > p;
		p.push({dis[i][i], i});
		while(p.size()) {
			int u = p.top().second;
			p.pop();
			if(viss[i][u]) continue ;
			viss[i][u] = 1;
			for(auto x : G[u]) {
				int v = x.second, w = x.first;
				if(viss[i][v]) continue ;
				if(dis[i][u] + w < dis[i][v]) {
					dis[i][v] = dis[i][u] + w;
					p.push({dis[i][v], v});
				}
			}
		}
	}
	while(q -- ) {
		int u, v;
		ll ans = maxx;
		cin >> u >> v;
		for(auto x : V[u]) {
			int uu = x.second, w = x.first;
			for(auto ls : V[v]) {
				int vv = ls.second, ww = ls.first;
				ll lss = dis[uu][vv] + ww;
				ans = min(ans, lss + w);
			}
		}
		cout << ans + w[u] + w[v] << "\n"; 
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
