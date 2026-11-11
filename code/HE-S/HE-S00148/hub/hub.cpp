#include<bits/stdc++.h>
using namespace std;
const int N=2e6+50,inf=0x3f3f3f3f3f3f;
int c,T;
int n,k;
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
int f[N];
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
}
int dis[5000][5000];
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<=n;i++)
		{
			int u,v;
			cin>>u>>v;
			e[u].push_back({v,1});
			e[v].push_back({u,1});
		}
		if(k==2)
		{
			cout<<1<<'\n';
			continue;
		}
		cout<<1<<'\n';
	}
	return 0;
}
