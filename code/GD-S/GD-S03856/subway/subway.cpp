#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e14;
int main () {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);	
	
	int c, n, m, d, q; cin >> c >> n >> m >> d >> q;
	
	vector<vector<ll>> dis(n + 1, vector<ll> (n + 1, INF));
	vector<vector<pair<int, ll>>> pl(m + 1);
	
	vector<ll> w(m + 1); 
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
		pl[i].reserve(d);		
	} 
	
	for (int i = 1; i <= n; i++) {
		int k; cin >> k;
		dis[i][i] = 0;
		while (k--) {
			int s; ll t; cin >> s >> t;
			pl[s].push_back({i, t});
		}
	}
	
	for (int s = 1; s <= m; s++) 
		for (int i = 0; i < (int)pl[s].size(); i++) 
			for (int j = i + 1; j < (int)pl[s].size(); j++) {
				int u = pl[s][i].first, v = pl[s][j].first;
				dis[u][v] = min(dis[u][v], pl[s][i].second + pl[s][j].second);
				dis[v][u] = min(dis[v][u], pl[s][i].second + pl[s][j].second);
			}
	
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) 
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	
	
//	for (int i = 1; i <= n; i++){
//		for (int j = 1; j <= n; j++)
//			cout << dis[i][j] << ' ';
//		cout << '\n';
//	}
	
	while (q--) {
		int x, y; cin >>x >> y;
		
		ll ans = INF;
		
		for (int i = 0; i < (int)pl[x].size(); i++)
			for (int j = 0; j < (int)pl[y].size(); j++) {
				int u = pl[x][i].first, v = pl[y][j].first;
				ans = min(ans, 
					pl[x][i].second + pl[y][j].second +
					dis[u][v]
					);
					
//				cout << "x = " << x << " y = " << y <<'\n'
//					 << "xt : " << u << " yt : " << v << '\n'
//					 << "x : " << pl[x][i].second << " y : " <<pl[y][j].second
//					 << "dis = " << dis[pl[x][i].first][pl[y][j].first] <<'\n';
			}
		
		cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
} 
