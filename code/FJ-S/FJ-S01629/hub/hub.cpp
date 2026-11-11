#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
vector<int> g[1000005];
int d[1000005];
int id=0;
void dfs1(int u,int fa)
{
	for(int v:g[u])
	{
		if(v==fa) continue;
		d[v]=d[u]+1;
		if(d[v]>d[id]) id=v;
		dfs1(v,u);
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		memset(d,0,sizeof d);
		cin>>n>>k;
		for(int i =1;i<=n;i++) g[i].clear();
		for(int i =1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs1(1,0);
		memset(d,0,sizeof d);
		dfs1(id,0);
		cout<<max(0,d[id]-k)<<'\n';
	}
	return 0;
}
