#include <bits/stdc++.h>
#define pli pair <ll, int>
#define mkp make_pair
using namespace std;

typedef long long ll;
const int N = 505;
const int M = 5e5 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int ysz, n, m, D, Q;
ll w[M], dis[N][N];
vector <pli> t[M];

int main(){

	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin >> ysz >> n >> m >> D >> Q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1, k; i <= n; i++){
		cin >> k;
		ll x, y;
		for(int j = 1; j <= k; j++){
			cin >> x >> y;
			t[x].emplace_back(mkp(y, i));
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	for(int i = 1; i <= n; i++) dis[i][i] = 0;
	for(int i = 1; i <= m; i++){
		int d = t[i].size();
		for(int x = 0; x < d - 1; x++){
			for(int y = x + 1; y < d; y++){
				int u = t[i][x].second, v = t[i][y].second;
				dis[u][v] = min(dis[u][v], t[i][x].first + t[i][y].first);
				dis[v][u] = dis[u][v];
			}
		}
	}
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	int x, y;
	while(Q--){
		cin >> x >> y;
		ll ans = INF;
		for(pli u : t[x]){
			for(pli v : t[y]){
				ans = min(ans, dis[u.second][v.second] + u.first + v.first);
			}
		}
		cout << ans + w[x] + w[y] << '\n';
	}

	return 0;
}