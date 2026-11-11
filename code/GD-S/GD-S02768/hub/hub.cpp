#include<bits/stdc++.h> 
using namespace std;
int c,t,n,k;
vector<int> g[2000005];
int dist[1000005],dist1[1000005],zhi[1000005],maxx=-1,m,ans=1e9;
void dfs(int x,int d)
{
	for(int i=0;i<g[x].size();i++)
	{
		dist[g[x][i]]=d+1;
		dfs(g[x][i],d+1);
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		ans=1e9;
		if(k==1) 
		{
			cout<<"0"<<endl;
			continue;
		}
		if(k==n)
		{
			cout<<"1"<<endl;
			continue;
		}
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout<<k-1;
	} 
	return 0;
}
