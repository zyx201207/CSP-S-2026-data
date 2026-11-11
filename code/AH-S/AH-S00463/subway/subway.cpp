#include<bits/stdc++.h>
using namespace std;
int w[500005],k[505],dis[500005],ans=INT_MAX;
vector<int> a[505],t[505],g[500005];
void dfs(int x,int y,int s,int e)
{
	if(x==y)
	{
		ans=min(ans,s);
		return ;
	}
	if(s>ans)
	{
		return ;
	}
	for(int i=0;i<g[x].size();i++)
	{
		int u=g[x][i];
		if(u==e)
		{
			continue;
		}
		for(int j=0;j<a[u].size();j++)
		{
			if(a[u][j]>x&&dis[a[u][j]]==0)
			{
				dis[x]=1;
				dfs(a[u][j],y,s+t[u][j]+t[u][i],u);
				dis[x]=0;
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1,u,v;j<=k[i];j++)
		{
			cin>>u>>v;
			g[u].push_back(i);
			a[i].push_back(u);
			t[i].push_back(v);
		}
	}
	for(int i=1,x,y;i<=q;i++)
	{
		cin>>x>>y;
		dfs(x,y,w[x]+w[y],0);
		cout<<ans<<"\n";
	}
}
