#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
const int M = 510;

ll c, n, m, d, q;

int w[N], a[N], t[N];
ll dis[M][M];

vector<pair<int,int> > g[N];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++){
			cin >> a[j] >> t[j];
			g[a[j]].push_back({i, t[j]});
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			dis[i][j] = 1e18;
		}
	}
	for(int i = 1; i <= n; i++)dis[i][i] = 0;
	for(int i = 1; i <= m; i++){
		for(int j = 0; j < g[i].size(); j++){
			for(int k = 0; k < g[i].size(); k++){
				if(j == k)continue;
				int u = g[i][j].first;
				int v = g[i][k].first;
				//cout << i << " " << u << " " << v << " " << g[i][j].second << " " << g[i][k].second << '\n';
				dis[u][v] = min((ll)g[i][j].second + g[i][k].second, dis[u][v]);
			}
		}
	}
	
	
	
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n; j ++){
			for(int k = 1; k <= n; k++){
				if(dis[i][k] && dis[j][k]);
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	
//	for(int i = 1; i <= n; i++){
//		for(int j = 1; j <= n; j++){
//			cout << dis[i][j] << " ";
//		}
//		cout << '\n';
//	}
	
	for(int i = 1; i <= q; i++){
		int u, v;
		cin >> u >> v;
		ll ans = 1e18;
		for(int j = 0; j < g[u].size(); j++){
			for(int k = 0; k < g[v].size(); k++){
				int a = g[u][j].first;
				int b = g[v][k].first;
				ans = min(ans,(ll) dis[a][b] + g[u][j].second + g[v][k].second);
			}
		}
		ans += w[u] + w[v];
		cout << ans << '\n';
	}
	return 0;
}
