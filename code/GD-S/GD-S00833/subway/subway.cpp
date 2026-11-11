#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+200;
int c,n,m,d,q;
int w[maxn];
int Dis[maxn][505];
set<int>s[maxn];
int dis[505][505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)
	{
		cin>>w[i];
	} 
	for(int i=1;i<=m;++i) for(int j=1;j<=n;++j) Dis[i][j]=1e9;
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) dis[i][j]=1e9;
	for(int i=1;i<=n;++i) dis[i][i]=0;
	for(int i=1;i<=n;++i)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;++j)
		{
			int d,t;
			cin>>d>>t;
			s[d].insert(i);
			Dis[d][i]=t;
		}
	}
	for(int i=1;i<=m;++i)
	{
		for(auto j:s[i])
		{
			for(auto k:s[i])
			{
				dis[j][k]=min(dis[j][k],Dis[i][j]+Dis[i][k]);
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			for(int k=1;k<=n;++k)
			{
				dis[j][k]=min(dis[j][k],dis[i][j]+dis[i][k]);
			}
		}
	}
	while(q--)
	{
		int u,v,ans=1e9;
		cin>>u>>v;
		if(u==v)
		{
			cout<<0<<'\n';
			continue;
		}
		for(auto i:s[u])
		{
			for(auto j:s[v])
			{
				if(i==j)
				{
					ans=min(ans,Dis[u][i]+Dis[v][j]);
				}
				ans=min(ans,Dis[u][i]+Dis[v][j]+dis[i][j]);
			}
		}
		cout<<ans+w[u]+w[v]<<'\n';
	}
} 
