#include<bits/stdc++.h>
using namespace std;
#define int long long
int min(int a,int b)
{
	return a<b?a:b;
}
int c,n,m,d,q,w[500005],k[505],g[505][505],dist[505][505];
vector<vector<int>> a,t;
vector<vector<pair<int,int>>> tsf;
void init()
{
	for(int i=1;i<=n;i++) for(int j=1;j<i;j++) g[i][j]=g[j][i]=1e18;
	for(int i=1;i<=m;i++)
	{
		if(tsf[i].empty()) continue;
		for(const pair<int,int>& a:tsf[i])
		{
			for(const pair<int,int>& b:tsf[i])
			{
				if(a.first==b.first) continue;
				g[a.first][b.first]=g[b.first][a.first]=min(g[a.first][b.first],a.second+b.second);
			}
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<i;j++) dist[i][j]=dist[j][i]=g[i][j];
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			if(i==k) continue;
			for(int j=1;j<i;j++)
			{
				if(j==k||i==j) continue;
				dist[i][j]=dist[j][i]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	a.assign(n+1,vector<int>());
	t.assign(n+1,vector<int>());
	tsf.assign(m+1,vector<pair<int,int>>());
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int x,y;cin>>x>>y;
			a[i].push_back(x);
			t[i].push_back(y);
			tsf[x].emplace_back(i,y);
		}
	}
	init();
	while(q--)
	{
		int x,y,ans=1e18;cin>>x>>y;
		for(const pair<int,int>& a:tsf[x])
		{
			for(const pair<int,int>& b:tsf[y])
			{
				ans=min(ans,dist[a.first][b.first]+a.second+b.second);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
