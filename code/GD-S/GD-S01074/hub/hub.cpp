#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int c,t,n,k,head[N],to[2 * N],nxt[2 * N],cnt,dis[N];
struct node{
	int id,s;
};
bool operator<(node a,node b)
{
	return a.s < b.s;
}
bool operator>(node a,node b)
{
	return a.s > b.s;
}
void add(int u,int v)
{
	to[++cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt;
}
priority_queue<node,vector<node>,greater<node> > q;
void dijkstra(int xx)
{
	memset(dis,0x3f,sizeof(dis));
	q.push({xx,0});
	dis[xx] = 0;
	while (!q.empty())
	{
		node f = q.top();
		q.pop();
		for (int i = head[f.id]; i; i = nxt[i])
		{
			if (dis[to[i]] > f.s + 1)
			{
				dis[to[i]] = f.s + 1;
				q.push({to[i],f.s + 1});
			}
		}
	}
}
void solve()
{
	memset(head,0,sizeof(head));
	scanf("%d%d",&n,&k);
	for (int i = 1,u,v; i < n; i++)
	{
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dijkstra(1);
	int maxid = 0,maxx = 0;
	for (int i = 1; i <= n; i++)
	{
		if (dis[i] > maxx)
		{
			maxx = dis[i];
			maxid = i;
		}
	}
	dijkstra(maxid);
	maxx = 0;
	for (int i = 1; i <= n; i++) maxx = max(maxx,dis[i]);
	printf("%d\n",(maxx - k + 3) / 3);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while (t--) solve();
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
