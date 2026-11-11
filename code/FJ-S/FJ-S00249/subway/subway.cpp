#include <bits/stdc++.h>
using namespace std;

#define int long long

int c,n,m,d,q,w[500010],k[510],dis[510][510],len[500010];

vector <pair <int,int>> edges[500010];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i = 1;i <= n;i++){
		dis[i][i] = 0;
	}
	for(int i = 1;i <= m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i = 1;i <= n;i++){
		scanf("%lld",&k[i]);
		for(int j = 1;j <= k[i];j++){
			int v,w;
			scanf("%lld%lld",&v,&w);
			edges[v].push_back({i,w});
		}
	}
	for(int i = 1;i <= m;i++){
		len[i] = edges[i].size();
		for(int j = 0;j < len[i];j++){
			for(int l = j + 1;l < len[i];l++){
				int u = edges[i][j].first;
				int v = edges[i][l].first;
				int w = edges[i][j].second + edges[i][l].second;
				dis[u][v] = min(dis[u][v],w);
				dis[v][u] = min(dis[v][u],w);
			}
		}
	}
	for(int l = 1;l <= n;l++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				dis[i][j] = min(dis[i][j],dis[i][l] + dis[l][j]);
			}
		}
	}
	while(q--){
		int x,y;
		scanf("%lld%lld",&x,&y);
		int ans = 1LL << 60;
		int len1 = len[x];
		int len2 = len[y];
		for(int i = 0;i < len1;i++){
			for(int j = 0;j < len2;j++){
				ans = min(ans,w[x] + w[y] + edges[x][i].second + edges[y][j].second + dis[edges[x][i].first][edges[y][j].first]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
