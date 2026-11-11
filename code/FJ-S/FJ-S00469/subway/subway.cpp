#include<bits/stdc++.h>
using namespace std;
int w[500005],cnt[500005];
long long dis[505][505],g[500005][25][2];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	memset(dis,0x3f,sizeof dis);
	int c,n,m,d,q,k,a,t,x,y;
	long long ans;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		dis[i][i]=0;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a>>t;
			g[a][++cnt[a]][0]=i;
			g[a][cnt[a]][1]=t;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=cnt[i];j++)
		{
			for(int k=j+1;k<=cnt[i];k++)
			{
				dis[g[i][j][0]][g[i][k][0]]=min(dis[g[i][j][0]][g[i][k][0]],g[i][j][1]+g[i][k][1]);
				dis[g[i][k][0]][g[i][j][0]]=min(dis[g[i][k][0]][g[i][j][0]],g[i][j][1]+g[i][k][1]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
			}
		}
	}
	while(q--)
	{
		ans=1e18;
		cin>>x>>y;
		for(int i=1;i<=cnt[x];i++)
		{
			for(int j=1;j<=cnt[y];j++)
			{
				ans=min(ans,dis[g[x][i][0]][g[y][j][0]]+g[x][i][1]+g[y][j][1]);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
