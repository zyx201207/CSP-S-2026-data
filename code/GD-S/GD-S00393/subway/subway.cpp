#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, ll>
const int N = 507, M = 5e5 + 7, D = 27;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int Case;
int n, m, d, q;
ll w[M];
vector< pii >g[M];
ll dis[N][N];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> Case >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for(int j = 1, x; j <= k; j++){
			ll y;
			cin >> x >> y;
			g[x].push_back(make_pair(i, y));
		} 
	}
	memset(dis, 0x3f, sizeof(dis));
	for(int i = 1; i <= n; i++) dis[i][i] = 0;
	for(int i = 1; i <= m; i++){
		int len = g[i].size();
		for(int j = 0; j < len; j++){
			for(int k = 0; k < len; k++){
				int u = g[i][j].first, v = g[i][k].first;
				dis[u][v] = min(dis[u][v], g[i][j].second + g[i][k].second);
			}
		}
	}
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	while(q--){
		int x, y;
		cin >> x >> y;
		ll ans = inf;
		for(auto tx : g[x]){
			for(auto ty : g[y]){
				ans = min(ans, w[x] + tx.second + dis[tx.first][ty.first] + ty.second + w[y]);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
} 
