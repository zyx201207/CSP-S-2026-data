#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int t,n,k,u,v,dep[N];
vector<int> g[N];
void dfs(int x)
{
	for(auto z:g[x])
	{
		if(dep[z]==0)
		{
			dep[z]=dep[x]+1;
			dfs(z);
		}
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>t>>t;
	while(t--)
	{
		for(int i=1;i<=n;i++)
		{
			g[i].clear();
		}
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		memset(dep,0,sizeof(dep));
		dfs(1);
		int mx=0,id=0;
		for(int i=2;i<=n;i++)
		{
			if(mx<dep[i])
			{
				mx=dep[i];
				id=i;
			}
		}
		memset(dep,0,sizeof(dep));
		dfs(id);
		mx=0;
		id=0;
		for(int i=1;i<=n;i++)
		{
			if(mx<dep[i])
			{
				mx=dep[i];
				id=i;
			}
		}
		cout<<ceil((mx-k+1)*1.0/3)<<endl;
	}
	return 0;
}
