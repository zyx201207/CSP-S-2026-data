#include<bits/stdc++.h>
using namespace std;
//多个起点的多源最短路，难点在于看出来和转换 
//注意t[i][j]1e9,dis long long
//可能重边，注意一下 
struct node{
	int t,u;
};
int w[500050];
int k[550];
vector<node> po[500050];

long long dis[550][550][550];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		int a,t;
		for(int j=1;j<=k[i];j++)
		{
			scanf("%d%d",&a,&t);
			po[a].push_back({t,i});
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=0;k<=n;k++)
			{
				if(i!=j) dis[i][j][k]=1e18;
			}
		}
	}
	//cout<<1;
	for(int x=1;x<=m;x++)
	{
		for(auto u:po[x])
		{
			for(auto v:po[x])
			{
				dis[u.u][v.u][0]=min(dis[u.u][v.u][0],1ll*u.t+v.t);
				//dis[v.u][u.u][0]=min(dis[v.u][u.u][0],u.t+v.t);
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j][k]=min(dis[i][j][k-1],dis[i][k][k-1]+dis[k][j][k-1]);
			}
		}
	}
	while(q--)
	{
		int s,e;
		scanf("%d%d",&s,&e);
		long long ans=1e18;
		//根据s,e
		for(auto sl:po[s])
		{
			for(auto el:po[e])
			{
				ans=min(ans,sl.t+el.t+dis[sl.u][el.u][n]);
				//cout<<sl.t+el.t+dis[sl.u][el.u][n]<<' ';
			}
		}
		cout<<ans+w[s]+w[e]<<'\n';
	}
	return 0;
}
