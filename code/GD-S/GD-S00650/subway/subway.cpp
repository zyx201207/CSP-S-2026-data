#include<bits/stdc++.h>
#define N 500007
#define M 507
#define ll long long
#define INF 10000000000000000
using namespace std;
struct Edge{
	int v, w;
};
int c, n, m, d, q;
int w[N];
vector<Edge> g1[N];
ll g[M][M];

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(i == j)g[i][j] = 0;
			else g[i][j] = INF;
		}
	}
	for(int i = 1;i <= n;i++){
		int k, a, t;
		cin >> k;
		for(int j = 1;j <= k;j++){
			cin >> a >> t;
			g1[a].push_back({i, t});
		}
	}
	for(int i = 1;i <= m;i++){
		for(int j = 0;j < g1[i].size();j++){
			ll u, v, w;
			u = g1[i][j].v;
			w = g1[i][j].w;
			for(int k = 0;k < j;k++){
				v = g1[i][k].v;
				w += g1[i][k].w;
				g[u][v] = g[v][u] = min(g[u][v], w);
			}
		}
	}
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			if(i == k)continue;
			for(int j = 1;j < i;j++){
				if(j == k)continue;
				g[i][j] = g[j][i] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
	while(q--){
		int s, t;
		cin >> s >> t;
		ll ans = INF;
		for(int i = 0;i < g1[s].size();i++){
			for(int j = 0;j < g1[t].size();j++){
				ans = min(ans, g1[s][i].w + g1[t][j].w + g[g1[s][i].v][g1[t][j].v]);
			}
		}
		cout << ans + w[s] + w[t] << '\n';
	}
	
	return 0;
}
