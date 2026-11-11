#include<bits/stdc++.h>
using namespace std;
long long u,v,anss,d[550][550],c,n,m,dd,qq,w[600000],a,t,k;
vector<pair<long long,long long>> g[600000];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	cin>>c>>n>>m>>dd>>qq;
	for(long long i=1;i<=m;i++)cin>>w[i];
	for(long long i=1;i<=n;i++)
	{
		cin>>k;
		for(long long j=1;j<=k;j++)
		{
			cin>>a>>t;
			g[a].push_back({t,i});
		}
	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=1;j<=n;j++)
		{
			d[i][j]=1e18;
		}
	}
	for(long long i=1;i<=n;i++)d[i][i]=0;
	for(long long i=1;i<=m;i++)
	{
		for(auto o:g[i])
		{
			for(auto p:g[i])
			{
				d[o.second][p.second]=min(d[o.second][p.second],o.first+p.first);
			}
		}
	}
	for(long long k=1;k<=n;k++)
	{
		for(long long i=1;i<=n;i++)
		{
			for(long long j=1;j<=n;j++)
			{
				d[j][i]=d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	while(qq--)
	{
		cin>>u>>v;
		anss=1e18;
	    for(pair<long long,long long> aa:g[u])
	    {
	    	for(pair<long long,long long> bb:g[v])
	    	{
	    		anss=min(anss,aa.first+bb.first+d[aa.second][bb.second]);
			}
		}
		cout<<anss+w[u]+w[v]<<endl;
	}
}
