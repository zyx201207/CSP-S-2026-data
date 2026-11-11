#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505, M = 500005, D = 22;
struct edge{
	int to, w;
};
vector<edge> g[M];
int c, n, m, d, q, W[M], dis[N][N], K[N], x;
signed main (){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i = 1; i <= m; i ++) scanf("%lld",&W[i]); 
	for(int i = 1; i <= n; i ++) for(int j = 1; j <= n; j ++) if(i!=j) dis[i][j] = 1e18;
	for(int i = 1; i <= n; i ++){
		scanf("%lld",&K[i]);
		for(int j = 1, u = 0, w = 0; j <= K[i]; j ++){
			scanf("%lld%lld",&u,&w);
			for(edge vv : g[u]){
				int v = vv.to, ww = vv.w;
				dis[i][v] = dis[v][i] = min(dis[i][v], w+ww);
			}
			g[u].push_back({i,w});
		}
	}
	for(int k = 1; k <= n; k ++){
		for(int i = 1; i <= n; i ++){
			for(int j = 1; j <= n; j ++){
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]); 
			}
		}
	}
	int u = 0, v = 0;
	while(q--){
		int ans = 1e18;
		scanf("%lld%lld",&u,&v);
		for(edge uu : g[u]){
			for(edge vv : g[v]){
				ans = min(ans, uu.w + vv.w + dis[uu.to][vv.to]);
			}
		}
		printf("%lld\n",ans + W[u] + W[v]);
	}
}
