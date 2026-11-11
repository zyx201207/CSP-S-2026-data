#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
struct node{
	int u,v,w;
};
int c,n,m,d,q;
int w[N+1];
vector<node> g[N+1];
bool vis[N+1];
int ans=INT_MAX;
void dfs(int x,int y,int r,int l)
{
	if(x==y)
	{
		ans=min(ans,r+l);
		//cout<<r+l<<" ";
		return;
	}
	vis[x]=1;
	for(int i=0;i<g[x].size();i++)
	{
		if(vis[g[x][i].v]==0)
			dfs(g[x][i].v,y,r+l,g[x][i].w);
	}
	vis[x]=0;
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		int a[k+5],b[k+5];
		for(int j=1;j<=k;j++)
			cin>>a[j]>>b[j];
		for(int j=1;j<k;j++)
		{
			for(int z=j+1;z<=k;z++)
			{
				node p;
				p.v=a[z];
				p.w=b[j]+b[z];
				g[j].push_back(p);
				p.v=a[j];
				g[z].push_back(p);
			}
		}
	}
	while(q--)
	{
		int x,y;
		int flag=0;
		cin>>x>>y;
		memset(vis,0,sizeof(vis));
		for(int i=0;i<g[x].size();i++)
		{
			if(g[x][i].v==y)
			{
				cout<<g[x][i].w+w[x]+w[y]<<"\n";
				flag=1;
			}
		}
		if(flag)continue;
		for(int i=0;i<g[x].size();i++)
			dfs(g[x][i].v,y,0,g[x][i].w);
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
