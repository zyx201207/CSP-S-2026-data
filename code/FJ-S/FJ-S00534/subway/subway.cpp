#include <bits/stdc++.h>
using namespace std;
long long w[1005];
long long dist[1005][1005];//第i条线路到第j条线路  换乘费用 
long long di[1005][1005];
vector<int> g[1005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%lld",&w[i]);
	memset(dist,0x3f,sizeof(dist));
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			long long x,y;
			scanf("%lld%lld",&x,&y);
			di[x][i]=y;
			g[x].push_back(i);
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(auto j:g[i])
		{
			for(auto k:g[i])
			if(j!=k) 
			{
				dist[j][k]=min(dist[j][k],di[i][k]+di[i][j]);
				dist[k][j]=min(dist[k][j],di[i][j]+di[i][k]);
			}
			else dist[j][k]=0,dist[k][j]=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			if(j!=k) 
			{
				dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
				dist[k][j]=min(dist[k][j],dist[k][i]+dist[i][j]);
			}
			else dist[j][k]=0,dist[k][j]=0;
		}
	}
	for(int i=1;i<=q;i++)
	{
		long long ans=1e18;
		int x,y;
		scanf("%d%d",&x,&y);
		for(auto u:g[x])
			for(auto v:g[y])
				ans=min(ans,dist[u][v]+di[x][u]+di[y][v]+w[x]+w[y]);	
		printf("%lld\n",ans);
	}
	return 0;
} 
