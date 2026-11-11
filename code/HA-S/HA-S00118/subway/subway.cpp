#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// n<=500,m<=5e5,k<=5e5,d<=20,q<=1e5
int c,n,m,d,qq;
ll dis[505];
bool vis[505];
ll w[505];
struct line
{
	int a;
	ll t;
};
struct edge
{
	int v;
	ll w;
};
struct point
{
	int p;
	ll w;
};
struct cmp
{
	bool operator()(point &a,point &b)
	{
		return a.w>b.w;
	}
};
vector<edge> e[505];
priority_queue<point,vector<point>,cmp> q;
void addedge(int u,int v,ll w)
{
	e[u].push_back((edge){v,w});
}
void dijkstra(int s)
{
	for(int i = 1;i <= m;i++)
	{
		dis[i]=(4611686018427388);
		vis[i]=0;
	}
	q.push((point){s,0});
	dis[s]=0;
	while(!q.empty())
	{
		point head = q.top();
		q.pop();
		if(vis[head.p]) continue;
		vis[head.p]=1;
		int now = head.p;
		for(int i = 0;i < e[now].size();i++)
		{
			int v = e[now][i].v;
			ll w = e[now][i].w;
			if(dis[now]+w<dis[v])
			{
				dis[v]=dis[now]+w;
				q.push((point){v,dis[v]});
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m>> d >> qq;
	for(int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++)
	{
		int k;cin >> k;
		vector<line> l;
		for(int j = 1;j <= k;j++)
		{
			int a,t;cin >> a >> t;
			l.push_back((line){a,t});
		}
		for(int u = 0;u < k;u++)
		{
			for(int v = 0;v < k;v++)
			{
				if(u==v) continue;
				addedge(l[u].a,l[v].a,l[u].t+l[v].t);
			}
		}
	}
	while(qq--)
	{
		int s,t;cin >> s >> t;
		dijkstra(s);
		cout << dis[t]+w[s]+w[t] << "\n";
	}
	return 0;
}
