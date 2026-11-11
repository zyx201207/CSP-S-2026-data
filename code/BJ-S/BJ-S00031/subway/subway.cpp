#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int M = 5e5 + 7;
const int N = 507;
int n, m, D, Q;
ll w[M], dis[N][N];

struct Edge{
	int k;
	vector <pair<int, ll> > adj;
}a[N];
vector <pair<int, ll> > g[M];

int main(){
	ios::sync_with_stdio(false);
	freopen("subway.in", "r", stdin); freopen("subway.out", "w", stdout);
	int C; cin >> C >> n >> m >> D >> Q;
	for(int i = 1; i <= m; ++i) cin >> w[i];
	for(int i = 1; i <= n; ++i){
		cin >> a[i].k;
		for(int j = 1; j <= a[i].k; ++j){
			int ax; ll tx; cin >> ax >> tx;
			a[i].adj.push_back({ax, tx});
			g[ax].push_back({i, tx});
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	for(int i = 1; i <= n; ++i) dis[i][i] = 0;
	for(int i = 1; i <= m; ++i){
		for(int j = 0; j < g[i].size(); ++j){
			int ax = g[i][j].first; ll tx = g[i][j].second;
			for(int k = j + 1; k < g[i].size(); ++k){
				int ay = g[i][k].first; ll ty = g[i][k].second;
				dis[ax][ay] = min(dis[ax][ay], tx + ty);
				dis[ay][ax] = dis[ax][ay];
			}
		}
	}
	for(int k = 1; k <= n; ++k)
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	while(Q--){
		int x, y; cin >> x >> y;
		ll ans = 1e18 + 7;
		for(int j = 0; j < g[x].size(); ++j){
			int ax = g[x][j].first; ll tx = g[x][j].second;
			for(int k = 0; k < g[y].size(); ++k){
				int ay = g[y][k].first; ll ty = g[y][k].second;
				ans = min(ans, tx + ty + dis[ax][ay]);
			}
		}
		cout << ans + w[x] + w[y] << "\n";
	}
	return 0;
}