#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+7;
const int M=507;
int c,n,m,d,q; 
int w[N];
int dis[M][M];
vector<pair<int,int> >g[N];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%lld",&k);
		for(int j=1;j<=k;j++)
		{
			int u,t;
			scanf("%lld%lld",&u,&t);
			g[u].push_back(make_pair(i,t));
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)
	{
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		int len=g[i].size();
		for(int j=0;j<len;j++)
		{
			int u=g[i][j].first,w_1=g[i][j].second;
			for(int k=j+1;k<len;k++)
			{
				int v=g[i][k].first,w_2=g[i][k].second;
				dis[u][v]=dis[v][u]=min(dis[u][v],w_1+w_2);
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y,ans=dis[0][0];
		scanf("%lld%lld",&x,&y);
		int len_1=g[x].size(),len_2=g[y].size();
		for(int j=0;j<len_1;j++)
		{
			for(int k=0;k<len_2;k++)
			{
				ans=min(ans,w[x]+w[y]+g[x][j].second+g[y][k].second+dis[g[x][j].first][g[y][k].first]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
