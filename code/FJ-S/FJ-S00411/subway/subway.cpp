#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int c,n,m,d,q,k[550];
struct sta
{
	int a;long long t;
};
vector<sta>h[500010];
long long dis[510][510],w[500010];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for (int i=1;i<=n;i++)for (int j=1;j<=n;j++)if (i!=j)dis[i][j]=1000000000000000000;
	for (int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		for (int j=1;j<=k[i];j++)
		{
			int s;
			long long ti;
			scanf("%d%lld",&s,&ti);
			h[s].push_back((sta){i,ti});
		}
	}
	for (int i=1;i<=m;i++)
	{
		int siz=h[i].size();
		for (int l=0;l<siz;l++)
		{
			for (int r=l+1;r<siz;r++)
			{
				int u=h[i][l].a,v=h[i][r].a;
				dis[v][u]=dis[u][v]=min(dis[u][v],h[i][l].t+h[i][r].t);
			}
		}
	}
	for (int k=1;k<=n;k++)for (int i=1;i<=n;i++)for (int j=1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for (int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		int sx=h[x].size(),sy=h[y].size();
		long long minn=1e18;
		for (int l=0;l<sx;l++)
		{
			for (int r=0;r<sy;r++)
			{
				int u=h[x][l].a,v=h[y][r].a;
				minn=min(minn,dis[u][v]+h[x][l].t+h[y][r].t);
			}
		}
		printf("%lld\n",minn+w[x]+w[y]);
	}
	return 0;
}
