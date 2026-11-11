#include<bits/stdc++.h> 
using namespace std;
int m,n,c,d,q,w[500005],x,y;
long long ans=1e9;
bool v[505][200005];
vector<pair<int,int>> g[500005];
dfs(int x,long long cnt)
{
	if(x==n+y) ans=min(ans,cnt+w[y]);
	for(int i=0;i<g[x].size();i++)
	{
		if(!v[i][g[x][i].first])
		{
			v[i][g[x][i].first]=1;
			dfs(g[x][i].first,cnt+g[x][i].second);
			v[i][g[x][i].first]=0;
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		for(int j=1;j<=x;j++)
		{
			int u,t;
			cin>>u>>t;
			g[i].push_back({n+u,t});
			g[n+u].push_back({i,t});
		}
	}
	while(q--)
	{
		cin>>x>>y; 
		ans=1e9;
		dfs(x+n,w[x]);
		cout<<ans<<endl;
	}
}

