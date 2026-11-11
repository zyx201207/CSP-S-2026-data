#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 510, M = 5e5 + 10;
ll c, n, m, d, q, w[M], k[N], dis[N][N], ans;
vector < pair < int, int > > g[N];
vector < pair < int, int > > g2[M];
int main(){
	freopen( "subway.in", "r", stdin );
	freopen( "subway.out", "w", stdout );
	cin >> c >> n >> m >> d >> q;
	for ( int i = 1; i <= m; i++) cin >> w[i];
	for ( int i = 1; i <= n; i++){
		cin >> k[i];
		for ( int j = 1; j <= k[i]; j++){
			ll x, y;
			cin >> x >> y;
			g[i].push_back( { x, y } );
			g2[x].push_back( { i, y } );
		}
	}
	for ( int i = 1; i <= n; i++) for ( int j = 1; j <= n; j++) dis[i][j] = 1e18;
	for ( int i = 1; i <= n; i++) dis[i][i] = 0;
	for ( int i = 1; i <= n; i++) for ( int j = 0; j < k[i]; j++){
		ll x = g[i][j].first, w1 = g[i][j].second;
		for ( int l = 0; l < g2[x].size(); l++){
			ll y = g2[x][l].first, w2 = g2[x][l].second;
			dis[i][y] = min( dis[i][y], w1 + w2 );
		}
	}
	for ( int l = 1; l <= n; l++) for ( int i = 1; i <= n; i++) for ( int j = 1; j <= n; j++){//fah
		dis[i][j] = min( dis[i][j], dis[i][l] + dis[l][j] );
		// zhe shi ge fu za du hen gao de san chong xun huan, fu za du shi O(n^3), xi wang bu yao TLE, wo zhen mei zhao le
	}
	for ( int i = 1; i <= q; i++){
		int x, y;
		cin >> x >> y;
		ans = 1e18;
		for ( int j = 0; j < g2[x].size(); j++) for ( int l = 0; l < g2[y].size(); l++){
			ll u = g2[x][j].first, v = g2[y][l].first, w1 = g2[x][j].second, w2 = g2[y][l].second;
			ans = min( ans, dis[u][v] + w1 + w2 );
			//cout << u << ' ' << v << ' ' << dis[u][v] << ' ' << w1 << ' ' << w2 << '\n';
		}
		cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}
