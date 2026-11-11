#include<iostream>
#include<cstdio>
#include<vector>
#define int long long
using namespace std;
int w[500005];
int a[505][505];
vector<pair<int,int> > f[500005];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		a[i][j]=1e18+7;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int ke,ae,te;
		cin>>ke;
		for(int j=1;j<=ke;j++)
		{
			cin>>ae>>te;
			f[ae].push_back({i,te});
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<f[i].size();j++)
		for(int l=0;l<j;l++)
		{
			int u=f[i][j].first,v=f[i][l].first;
			a[u][v]=a[v][u]=min(a[u][v],f[i][j].second+f[i][l].second);
		}
	}
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		if(i==j||i==k||j==k)
			continue;
		a[i][j]=a[j][i]=min(a[i][j],a[i][k]+a[k][j]);
	}
	for(int i=1;i<=n;i++)
		a[i][i]=0;
	while(q--)
	{
		int fr,to;
		cin>>fr>>to;
		int ans=1e18+7;
		for(int i=0;i<f[fr].size();i++)
		for(int j=0;j<f[to].size();j++)
		{
			int u=f[fr][i].first,v=f[to][j].first;
			ans=min(ans,a[u][v]+f[fr][i].second+f[to][j].second);
		}
		cout<<ans+w[fr]+w[to]<<'\n';
	}
	return 0;
}
