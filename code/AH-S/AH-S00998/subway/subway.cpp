#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int c, m, n, d, q;
vector<pair<int, ll> > subway[500005];
ll dis[505][505], t[500005];

int main() {
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> c >> m >> n >> d >> q;
	for(int i = 1; i <= n; i++)
		cin >> t[i];
	for(int i = 1; i <= m; i++) {
		int k; cin >> k;
		for(int j = 1; j <= k; j++) {
			int x; ll y; cin >> x >> y;
			subway[x].push_back({i, y});
		} 
	} 
	memset(dis, 0x3f, sizeof(dis));
	for(int i = 1; i <= m; i++) dis[i][i] = 0;
	for(int x = 1; x <= n; x++) {
		for(int i = 0; i < subway[x].size(); i++)
			for(int j = i + 1; j < subway[x].size(); j++) {
				int u = subway[x][i].first, v = subway[x][j].first;
				ll w = subway[x][i].second + subway[x][j].second;
				dis[u][v] = dis[v][u] = min(dis[u][v], w);
			}
	}
	for(int k = 1; k <= m; k++)
		for(int i = 1; i <= m; i++)
			for(int j = 1; j <= m; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	while(q--) {
		int x, y; cin >> x >> y;
		ll ans = INF;
		for(int i = 0; i < subway[x].size(); i++)
			for(int j = 0; j < subway[y].size(); j++) {
				int u = subway[x][i].first, v = subway[y][j].first;
				ll w = subway[x][i].second + subway[y][j].second;
				if(dis[u][v] < INF) ans = min(ans, dis[u][v] + w);
			}
		cout << ans + t[x] + t[y] << endl;
	}
	return 0;
}
/*
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
