#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
struct edge{int v; ll w;};
struct node{ll dis;int id;};
struct Query{int y,id;};

const int N=510,M=5e5+10,Q=1e5+10;
const ll inf=1e18;
int c,n,m,D,q;
ll w[M],ans[Q];
vector<edge> g[M+N];
vector<Query> query[M]; 

ll d[M+N];
bool v[M+N];
int rest;
bool need[M];
void dijkstra(int s)
{
	for(int i=1;i<=n+m;i++) d[i]=inf,v[i]=false;
	auto cmp=[](node x,node y){return x.dis>y.dis;};
	priority_queue<node,vector<node>,decltype(cmp)> pq(cmp);
	d[s]=0,pq.push({d[s],s});
	while(!pq.empty())
	{
		int u=pq.top().id; pq.pop();
		if(v[u]) continue;
		v[u]=true;
		if(need[u]) rest--;
		if(rest==0) return;
		for(edge e:g[u])
			if(d[u]+e.w<d[e.v])
			{
				d[e.v]=d[u]+e.w;
				pq.push({d[e.v],e.v});
			}
	}
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>n>>m>>D>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k; cin>>k;
		for(int j=1;j<=k;j++)
		{
			int v; ll w; cin>>v>>w;
			g[i+m].push_back({v,w});
			g[v].push_back({i+m,w});	
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y; cin>>x>>y;
		query[x].push_back({y,i});
	}
	for(int i=1;i<=m;i++)
	{
		if(query[i].size()==0)
			continue;
		rest=query[i].size();
		for(int j=0;j<query[i].size();j++)
			need[query[i][j].y]=true;
		dijkstra(i);
		for(int j=0;j<query[i].size();j++)
		{
			need[query[i][j].y]=false;
			ans[query[i][j].id]=d[query[i][j].y]+w[i]+w[query[i][j].y];
		}
	}
	for(int i=1;i<=q;i++)
		cout<<ans[i]<<endl;
	return 0;
}

