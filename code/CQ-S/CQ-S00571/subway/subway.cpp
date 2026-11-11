#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int C,n,m,D,Q;
long long a[N];
vector<pair<int,long long> >v[N];
long long f[505][505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>C>>n>>m>>D>>Q;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x;
			long long t;
			cin>>x>>t;
			v[x].push_back(make_pair(i,t));
		}
	}
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<(int)v[i].size();j++)
		{
			for(int k=j+1;k<(int)v[i].size();k++)
			{
				int U=v[i][j].first,V=v[i][k].first;
				f[U][V]=min(f[U][V],v[i][j].second+v[i][k].second);
				f[V][U]=min(f[V][U],v[i][j].second+v[i][k].second);
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
	while(Q--)
	{
		int x,y;
		cin>>x>>y;
		long long ans=9e18;
		for(int i=0;i<(int)v[x].size();i++)
		{
			for(int j=0;j<(int)v[y].size();j++)
			{
				int U=v[x][i].first,V=v[y][j].first;
				ans=min(ans,a[x]+a[y]+f[U][V]+v[x][i].second+v[y][j].second);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
