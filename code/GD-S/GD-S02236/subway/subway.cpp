#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define ll long long
#define pli pair<ll,int> 
const int N = 505;
const int M = 5e5+5;
int w[M];
int t[M];
vector<int> ml[M];
struct Edge
{
	int to,nxt,w;
}eg[2*(N+M)];
int head[N+M],egcnt;
void add(int u, int v, int w)
{
	eg[++egcnt].to = v;
	eg[egcnt].w = w;
	eg[egcnt].nxt = head[u];
	head[u] = egcnt;
}
ll dist[N+M];
bool vis[N+M];
int n,m;
void Dijkstra(int x)
{
	priority_queue<pli,vector<pli>,greater<pli>> pq;
	pq.push({0,x});
	for (int i = 1; i <= n+m; i++)
	{
		dist[i] = 1e18;
		vis[i] = 0;
	}
	dist[x] = 0;
	while (!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (int i = head[u]; i; i = eg[i].nxt)
		{
			int v = eg[i].to, w = eg[i].w;
			if (dist[v] > dist[u]+w)
			{
				dist[v] = dist[u]+w;
				pq.push({dist[v],v});
			}
		}
	}
}
int read()
{
	char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	int x = 0;
	while ('0' <= c &&  c <= '9')
	{
		x *= 10;
		x += c-'0';
		c = getchar();
	} 
	return x;
}
const int Q = 1e5+5;
struct Query
{
	int x,y,idx;
	void readq(int i)
	{
		x = read();
		y = read();
		idx = i;
	}
}qry[Q];
bool cmp(Query x, Query y)
{
	return x.x < y.x;
}
ll ans[Q];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,d,q;
	c = read();
	n = read();
	m = read();
	d = read();
	q = read();
	for (int i = 1; i <= m; i++) w[i] = read();
	for (int i = 1; i <= n; i++) 
	{
		int k;
		k = read();
		for (int j = 1; j <= k; j++)
		{
			int a,t;
			a = read();
			t = read();
			ml[a].push_back(i);
			add(a,m+i,t);
			add(m+i,a,t);
		}
	}
	for (int i = 1; i <= q; i++) qry[i].readq(i);
	sort(qry+1,qry+q+1,cmp);
	for (int i = 1; i <= q; i++)
	{
		if (qry[i].x != qry[i-1].x)
		{
			Dijkstra(qry[i].x);
			ans[qry[i].idx] = dist[qry[i].y]+w[qry[i].x]+w[qry[i].y];
		}
		else ans[qry[i].idx] = dist[qry[i].y]+w[qry[i].x]+w[qry[i].y];
	}
	for (int i = 1; i <= q; i++) cout << ans[i] << "\n";
	return 0;
}

