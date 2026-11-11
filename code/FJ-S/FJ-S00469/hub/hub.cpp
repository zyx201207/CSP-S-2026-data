#include<bits/stdc++.h>
using namespace std;
struct node
{
	int v,dis;
	bool operator<(node x)const
	{
		return dis<x.dis;
	} 
};
priority_queue<node>pq;
vector<pair<int,int>>g[1000005];
int dep[1000005];
bool vis[1000005];
int d,p,e,cut,c;
void dfs(int fa,int u,int dis)
{
	if(dis>d)
	{
		d=dis;
		p=u;
	}
	int v,id;
	for(int i=0;i<g[u].size();i++)
	{
		v=g[u][i].first;
		id=g[u][i].second;
		if(v!=fa and id!=cut)
		{
			dfs(u,v,dis+1);
		}
	}
	return;
}
bool rec(int fa,int u,int dis)
{
	int v,id;
	for(int i=0;i<g[u].size();i++)
	{
		v=g[u][i].first;
		id=g[u][i].second;
		if(v!=fa and id!=cut)
		{
			if(rec(u,v,dis+1))
			{
				if(dis==d/2)
				{
					e=id;
					c=u;
				}
				return 1;
			}
		}
	}
	return (u==p);
}
void dfs1(int fa,int u)
{
	dep[u]=0;
	int v,id;
	for(int i=0;i<g[u].size();i++)
	{
		v=g[u][i].first;
		id=g[u][i].second;
		if(v!=fa and id!=cut)
		{
			dfs1(u,v);
			dep[u]=max(dep[u],dep[v]+1);
		}
	}
	return;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	int c3,T,n,k,u,v,s,t,c1,c2,ans,id;
	cin>>c3>>T;
	while(T--)
	{
		memset(vis,0,sizeof vis);
		memset(dep,0,sizeof dep);
		s=0;
		t=0;
		d=0;
		c1=0;
		c2=0;
		d=0;
		p=0;
		c=0;
		cut=0;
		while(pq.size())
		{
			pq.pop();
		}
		ans=0;
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			g[i].clear();
		}
		for(int i=1;i<n;i++)
		{
			cin>>u>>v;
			g[u].push_back({v,i});
			g[v].push_back({u,i});
		}
		cut=0;
		d=0;
		dfs(0,1,0);
		s=p;
		d=0;
		dfs(0,s,0);
		t=p;
		rec(0,s,0);
		cut=e;
		d=0;
		dfs(0,s,0);
		c=s;
		rec(0,s,0);
		c1=c;
		d=0;
		dfs(0,t,0);
		c=t;
		rec(0,t,0);
		c2=c;
		dfs1(0,c1);
		dfs1(0,c2);
		pq.push({c1,dep[c1]});
		pq.push({c2,dep[c2]});
		vis[c1]=1;
		vis[c2]=1;
		while(!pq.empty())
		{
			if(k==0)
			{
				ans=pq.top().dis+1;
				break;
			}
			u=pq.top().v;
			pq.pop();
			k--;
			for(int i=0;i<g[u].size();i++)
			{
				v=g[u][i].first;
				id=g[u][i].second;
				if(id!=cut and !vis[v])
				{
					vis[v]=1;
					pq.push({v,dep[v]});
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
