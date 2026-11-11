#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,int>
const ll INF=-1e18;
vector<pii>vt[510];
ll dist[510],w1[510];

void dij(int s)
{
	priority_queue<pii>pq;
	pq.push(make_pair(0,s));
	while(!pq.empty())
	{
		pii pr=pq.top();
		pq.pop();
		ll d=pr.first;
		int u=pr.second;
		if(dist[u]<d)
		{
			dist[u]=d;
//			continue;
		}
		for(int i=0;i<vt[u].size();i++)
		{
//			cout<<1<<endl;
			pii pv=vt[u][i];
			ll w=pv.first;
			int v=pv.second;
//			if(v==u) continue;
			cout<<u<<" "<<v<<" "<<dist[u]+w<<endl;
			if(dist[u]+w>dist[v])
			{
				dist[v]=dist[u]+w;
				pq.push(make_pair(dist[v],v));
//				cout<<dist[v]<<endl;
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	ll c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w1[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			ll v,w;
			cin>>v>>w;
			vt[i].push_back(make_pair(-w,v));
			vt[v].push_back(make_pair(-w,i));
		}
	}
	while(q--)
	{
		for(int i=1;i<=n;i++) dist[i]=INF;
		int x,y;
		cin>>x>>y;
		dij(x);
		for(int i=1;i<=m;i++) cout<<dist[i]<<" ";
		cout<<endl;
		cout<<dist[y]+w1[x]+w1[y]<<endl;
	}
	return 0;
}

