#include<bits/stdc++.h>
using namespace std;
#define int long long
//将一条线看作一个点，对于每个真正的点，用O(m*d^2)将线与线连上，再跑floyd，O(q*d^2)查询 
//1-15,20-23 估分76
int c,n,m,d,q,dis[505][505],a[500005];
vector<int> g[500005],w[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			int a,t;
			scanf("%lld%lld",&a,&t);
			g[a].push_back(i);
			w[a].push_back(t);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			dis[i][j]=1e18;
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<g[i].size();j++){
			for(int k=j+1;k<g[i].size();k++){
				int u=g[i][j],v=g[i][k];
				dis[u][v]=dis[v][u]=min(dis[u][v],w[i][j]+w[i][k]);
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int x,y,ans=1e18;
		scanf("%lld%lld",&x,&y);
		for(int i=0;i<g[x].size();i++)
			for(int j=0;j<g[y].size();j++)
				ans=min(ans,dis[g[x][i]][g[y][j]]+w[x][i]+w[y][j]);
		printf("%lld\n",ans+a[x]+a[y]);
	}
	return 0;
}
