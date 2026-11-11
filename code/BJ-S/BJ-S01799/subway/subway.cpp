#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define ull unsigned long long
#define i128 __int128
#define pii pair<int,int>
#define inf 1000000000
#define infl 1000000000000000000ll
#define ls (p<<1)
#define rd (p<<1|1)
const int N=5e5+5;
const int M=1e7+5;
int c,n,m,D,q,a[N],dis[N][21],vis[N][21],ans[N];
struct Edge
{
	int v,d,w;
};
struct node
{
	int u,d,dis;
	bool operator<(const node &x) const
	{
		return x.dis<dis;
	}
};
vector<int> val[N];
vector<Edge> e[N][21];
vector<pii> Q[N];
void add(int u,int d,int v,int dv,int w)
{
	e[u][d].push_back({v,dv,w});
}
void dijkstra(int s)
{
	for(int i=0;i<=m;i++)
	{
		for(int d=0;d<val[i].size();d++) dis[i][d]=infl,vis[i][d]=0;
	}
	priority_queue<node> q;
	e[0][0].clear();
	for(int i=0;i<val[s].size();i++) add(0,0,s,i,val[s][i]);
	dis[0][0]=0;
	vis[0][0]=0;
	q.push({0,0,0});
	while(q.size())
	{
		int u=q.top().u,d=q.top().d;
		q.pop();
		if(vis[u][d]) continue;
		// cout<<u<<' '<<d<<endl;
		vis[u][d]=1;
		for(int i=0;i<val[u].size();i++)
		{
			if(i==d) continue;
			int w=val[u][d]+val[u][i];
			if(dis[u][i]>dis[u][d]+w)
			{
				// cout<<u<<' '<<i<<' '<<d<<endl;
				dis[u][i]=dis[u][d]+w;
				q.push({u,i,dis[u][i]});
			}
		}
		for(auto x:e[u][d])
		{
			int v=x.v,dn=x.d,w=x.w;
			if(dis[v][dn]>dis[u][d]+w)
			{
				// cout<<u<<' '<<v<<' '<<dn<<' '<<w<<endl;
				dis[v][dn]=dis[u][d]+w;
				q.push({v,dn,dis[v][dn]});
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>D>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		vector<int> P;
		while(k--)
		{
			int v,t;
			cin>>v>>t;
			val[v].push_back(t);
			P.push_back(v);
		}
		for(int j=0;j<P.size()-1;j++)
		{
			int u=P[j],v=P[j+1];
			add(u,val[u].size()-1,v,val[v].size()-1,0);
			add(v,val[v].size()-1,u,val[u].size()-1,0);
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		Q[x].push_back({y,i});
	}
	for(int i=1;i<=m;i++) val[i].push_back(a[i]);
	for(int i=1;i<=m;i++)
	{
		if(Q[i].size()) dijkstra(i);
		for(auto x:Q[i])
		{
			int y=x.first,id=x.second;
			ans[id]=dis[y][val[y].size()-1]+a[i];
		}
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<endl;
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/