#include<bits/stdc++.h>
using namespace std;
const int N=1e6+50,inf=0x3f3f3f3f3f3f;
int c,n,d,Q,m;
int w[N],k[N],a[501][100000],t[501][100000],st=1000,l=10000;
struct node{
	int id,dis;
	bool operator < (const node x) const{
		return x.dis<dis;
	}
};
struct edge{
	int to,w;
};
priority_queue<node> q;
vector<edge> e[N];
int f[1000000];
inline int dijkstra(int str,int en)
{
	memset(f,0x3f,sizeof f);
	while(!q.empty()) q.pop();
	f[str]=0;
 	q.push({str,0});
 	while(!q.empty())
 	{
 		int x=q.top().id;
 		if(f[x]!=q.top().dis)
 		{
 			q.pop();
 			continue;
		}
		q.pop();
		for(int i=0;i<e[x].size();i++)
		{
			if(f[e[x][i].to]>f[x]+e[x][i].w)
			{
				f[e[x][i].to]=f[x]+e[x][i].w;
				q.push({e[x][i].to,f[e[x][i].to]});
			}
		}
	}
	return f[en];
}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
		e[i].push_back({i+st,w[i]});
		e[i+st].push_back({i,w[i]});
	}
	for(int i=1;i<=n;i++) 
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			e[a[i][j]+st].push_back({i+l,t[i][j]});
			e[i+l].push_back({a[i][j]+st,t[i][j]});
			e[a[i][j]].push_back({i+l,t[i][j]+w[a[i][j]]});
			e[i+l].push_back({a[i][j],t[i][j]+w[a[i][j]]});
		}
	}
	for(int i=1;i<=Q;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<dijkstra(x,y)<<'\n';
	}
	return 0;
}
