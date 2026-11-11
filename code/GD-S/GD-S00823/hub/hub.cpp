#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> pa,sz;
vector<bool> vis;
vector<int> v;
void init(int ss)
{
	for(int i=0;i<ss;i++)
	{
		pa[v[i]]=v[i];	
		sz[v[i]]=1;
	} 
}
int find(int x)
{
	if(x==pa[x]) return x;
	return pa[x]=find(pa[x]);
}
void unite(int x,int y)
{
	int fx=find(x);
	int fy=find(y);
	if(fx==fy) return ;
	if(sz[fx]<sz[fy])
	{
		pa[fx]=fy;
		sz[fy]+=sz[fx];
		return ;
	}
	else
	{
		pa[fy]=fx;
		sz[fx]+=sz[fy];
		return ;
	}
}
int ans;
void dfs(int k,int n)
{
	if(k==0)
	{
		int ss=v.size();
		init(ss);
		for(int i=0;i<ss;i++)
		{
			for(int j=0;j<ss;j++)
			{
				if(adj[v[i]][v[j]]==1)
				{
					unite(v[i],v[j]);
				}	
			} 
		}
		set<int> st;
		for(int i=0;i<ss;i++)
		{
			st.insert(find(v[i])); 
		}
		int sts=st.size();
		if(sts<=2) ans++;
		return;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				v.push_back(i);
				vis[i]=1;
				dfs(k-1,n);
				v.pop_back();
				vis[i]=0;
			}
		}
	}
}
int main()
{
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		int n,k;
		cin>>n>>k;
		adj.assign(n+5,vector<int>(n+5,0));
		for(int i=0;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			adj[u][v]=1;
			adj[v][u]=1;
		}
		vis.assign(n+5,0);
		for(int i=1;i<=n;i++) vis[i]=0;
		v.clear();
		dfs(k,n);
		cout<<ans<<'\n';
	}
	return 0;	
} 
