#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a,k[505];
long long w[500005],t,dis[505][505];
vector<pair<int,long long>> g[500505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)
	{
		dis[i][i]=0;
		for(int j=i+1;j<=n;j++)
		{
			dis[i][j]=1e18;
			dis[j][i]=1e18;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a>>t;
			g[m+i].push_back({a,t});
			g[a].push_back({(m+i),t});
		}
	}
	for(int u=1;u<=n;u++)
	{
		for(auto x:g[m+u])
		{
			int i=x.first;
			long long z=x.second;
			for(auto y:g[i])
			{
				int v=y.first;
				long long zz=y.second;
				dis[u][v-m]=min(dis[u][v-m],z+zz);
				dis[v-m][u]=dis[u][v-m];
			}
		}
	}
	for(int l=1;l<=n;l++)
	{
		for(int u=1;u<=n;u++)
		{
			for(int v=1;v<=n;v++)
			{
				if(u==v)
				{
					continue;
				}
				dis[u][v]=min(dis[u][v],dis[u][l]+dis[l][v]);
				dis[v][u]=dis[u][v];
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int u,v;
		cin>>u>>v;
		long long ans=1e18;
		for(auto x:g[u])
		{
			int j=x.first;
			long long z=x.second;
			for(auto y:g[v])
			{
				int l=y.first;
				long long zz=y.second;
				ans=min(ans,(w[u]+w[v]+z+zz+dis[j-m][l-m]));
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
