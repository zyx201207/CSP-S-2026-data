#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=510+1e6;
ll c,n,m,D,q,w,k,u,v;
vector<pair<ll,ll>> e[N];
ll d[N];
void dij(int root)
{
	bool vis[N];
	memset(vis,0,sizeof(vis));
	memset(d,0x3f,sizeof(d));
	priority_queue<pair<ll,ll>> q;
	d[root]=0;
	q.push({0,root});
	while(!q.empty())
	{
		int u=q.top().second;q.pop();
		if(vis[u])
			continue;
		vis[u]=1;
		for(auto a:e[u])
		{
			int v=a.first,w=a.second;
			if(d[u]+w<d[v])
			{
				d[v]=d[u]+w;
				q.push({-d[v],v});
			}
		} 
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>D>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w;
		e[i].push_back({i+m,w});
		e[i+m].push_back({i,w});
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>u>>w;
			e[u+m].push_back({2*m+i,w});
			e[2*m+i].push_back({u+m,w});
		}
	}
	while(q--)
	{
		cin>>u>>v;
		dij(u);
		cout<<d[v]<<"\n";
	}
	return 0;
}
