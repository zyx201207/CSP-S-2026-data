#include <iostream>
#include <cstdio>
using namespace std;
int c,n,m,d,q,k,a,t,x,y;
long long w[500001],dis[501][501];
pair<int,long long> qwq[500001][21];
int cnt[500001];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a>>t;
			qwq[a][++cnt[a]].first=i;
			qwq[a][cnt[a]].second=t;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			dis[i][j]=1e18;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=cnt[i];j++)
		{
			for(int k=1;k<j;k++)
			{
				int u=qwq[i][j].first,v=qwq[i][k].first;
				dis[u][v]=min(dis[u][v],qwq[i][j].second+qwq[i][k].second);
				dis[v][u]=dis[u][v];
			}
		}
	}
	for(int k=1;k<=m;k++)
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--)
	{
		cin>>x>>y;
		long long ans=1e18;
		for(int i=1;i<=cnt[x];i++)
		{
			for(int j=1;j<=cnt[y];j++)
			{
				int u=qwq[x][i].first,v=qwq[y][j].first;
				ans=min(ans,dis[u][v]+qwq[x][i].second+qwq[y][j].second);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
