#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505,M=5e5+5;
int c,n,m,d,q;
ll w[M],f[N][N];
vector<pair<int,ll> > v[M];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int x=1;x<=m;x++)
	{
		cin>>w[x];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x;
			ll y;
			cin>>x>>y;
			v[x].push_back({i,y});
		}
	}
	for(int x=1;x<=n;x++)
	{
		for(int y=1;y<=n;y++)
		{
			f[x][y]=1e18;
		}
		f[x][x]=0;
	}
	for(int x=1;x<=m;x++)
	{
		for(int i=0;i<v[x].size();i++)
		{
			for(int j=i+1;j<v[x].size();j++)
			{
				pair<int,ll> u1=v[x][i],u2=v[x][j];
				f[u1.first][u2.first]=min(f[u1.first][u2.first],u1.second+u2.second);
				f[u2.first][u1.first]=min(f[u2.first][u1.first],u1.second+u2.second);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int x=1;x<=n;x++)
		{
			for(int y=1;y<=n;y++)
			{
				f[x][y]=min(f[x][y],f[x][i]+f[i][y]);
			}
		}
	}
	while(q--)
	{
		int s,t;
		cin>>s>>t;
		ll ans=1e18;
		for(int i=0;i<v[s].size();i++)
		{
			for(int j=0;j<v[t].size();j++)
			{
				pair<int,ll> u1=v[s][i],u2=v[t][j];
				ans=min(ans,u1.second+f[u1.first][u2.first]+u2.second);
			}
		}
		cout<<ans+w[s]+w[t]<<'\n';
	}
	return 0;
}
