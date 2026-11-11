#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+500+10,M=500+10;
struct edge{
	int to,w;
};
vector<edge> g[N];
int w[N],idx[N];
int dis[M][M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)dis[i][j]=1e18;
	}
	for(int i=1;i<=m;i++){
		scanf("%lld",w+i);
	}
	int tot=n;
	for(int i=1;i<=n;i++){
		int k;
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			int x,t;
			scanf("%lld%lld",&x,&t);
			if(!idx[x])idx[x]=++tot;
			x=idx[x];
			g[i].push_back({x,t});
			g[x].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
	}
	for(int i=n+1;i<=tot;i++){
		for(int j=0;j<g[i].size();j++){
			for(int k=j+1;k<g[i].size();k++){
				int u=g[i][j].to,v=g[i][k].to;
				dis[u][v]=dis[v][u]=min(dis[u][v],g[i][j].w+g[i][k].w);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		scanf("%lld%lld",&x,&y);
		int res=w[x]+w[y],mn=5e18;
		for(auto i:g[idx[x]]){
			for(auto j:g[idx[y]]){
				mn=min(mn,dis[i.to][j.to]+i.w+j.w);
			}
		}
		printf("%lld\n",res+mn);
	}
} 
