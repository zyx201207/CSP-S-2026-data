#include<bits/stdc++.h>
using namespace std;
long long f[505][505];
long long w[500005];
int k[505];
vector<pair<int,long long> > g[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][j]=1e18;
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		int xx,yy;
		for(int j=1;j<=k[i];j++)
		{
			cin>>xx>>yy;
			g[xx].push_back({i,yy});
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<g[i].size();j++)
		{
			for(int k=0;k<g[i].size();k++)
			{
				f[g[i][j].first][g[i][k].first]=min(f[g[i][j].first][g[i][k].first],g[i][j].second+g[i][k].second);
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	int x,y;
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		if(x==y)
		{
			cout<<"0\n";
			continue ;
		}
		long long ans=1e18;
		for(int j=0;j<g[x].size();j++)
		{
			for(int k=0;k<g[y].size();k++)
			{
				ans=min(ans,f[g[x][j].first][g[y][k].first]+g[x][j].second+g[y][k].second);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
}
