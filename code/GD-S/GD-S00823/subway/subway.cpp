#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> w;
vector<vector<int>> a;
vector<vector<ll>> t;
vector<vector<pair<int,ll>>> adj;
vector<ll> dist;
void dijkstra(int s)
{
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
	dist[s]=0;
	pq.push({0,s});
	while(!pq.empty())
	{
		auto cur=pq.top();
		pq.pop();
		ll d=cur.first;
		ll u=cur.second;
		if(d>dist[u]) continue;
		for(auto nxt : adj[u])
		{
			ll w=nxt.second;
			ll v=nxt.first;
			if(dist[v]>dist[u]+w)
			{
				dist[v]=dist[u]+w;
				pq.push({dist[v],v});
			}
		}
	}
}
int main()
{
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	dist.assign(m+5,1e18);
	w.assign(m+5,0);
	a.assign(n+5,vector<int>(m+5,0));
	t.assign(n+5,vector<ll>(m+5,0));
	adj.assign(2*m+n+10,vector<pair<int,ll>>(2*m+n+10));
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	int dot=m+1,node=n+m+1;
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[i][j]>>t[i][j];
			adj[a[i][j]].push_back({dot,0});
			adj[dot].push_back({a[i][j],0});
			adj[node].push_back({a[i][j],t[i][j]});//一个站点对应一个站台 
			adj[a[i][j]].push_back({node,t[i][j]});
			node++;
		}
		dot++;//一条线路对应一个虚拟点 
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		for(int i=1;i<=m;i++) dist[i]=2e18;
		dijkstra(x);
		cout<<w[x]+w[y]+dist[y]<<'\n';
	} 
	return 0;
}
