#include<bits/stdc++.h>
#define int long long
#define mk make_pair
using namespace std;
const int N = 5e2 + 10,M = 5e5 + 10,inf = 1e17;
int c,n,m,d,Q;
int w[M];
int k[N],a[M],t[M];
int dis[M];
bool vis[M];
priority_queue<pair<int,int> > q;
int hd[M + N],nxt[M << 2],to[M << 2],val[M << 2],cnt;
void add(int u,int v,int w)
{
	cnt ++;
	nxt[cnt] = hd[u];
	hd[u] = cnt;
	to[cnt] = v;
	val[cnt] = w;
	return ;
}
void dij(int st,int en)
{
	while(! q.empty())
	{
		q.pop();
	}
	for(int i = 1;i <= m + n;i ++)
	{
		dis[i] = inf;
		vis[i] = 0;
	}
	dis[st] = 0;
	q.push(mk(0,st));
	while(! q.empty())
	{
		int u = q.top().second;
		q.pop();
		if(vis[u])
		{
			continue;
		}
		vis[u] = 1;
		for(int i = hd[u];i;i = nxt[i])
		{
			int v = to[i],w1 = val[i];
			if(dis[v] > dis[u] + w1)
			{
				dis[v] = dis[u] + w1;
				if(v == en)
				{
					return ;
				}
				q.push(mk(-dis[v],v));
			}
		}
	}
	return ;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> c >> n >> m >> d >> Q;
	for(int i = 1;i <= m;i ++)
	{
		cin >> w[i];
	}
	for(int i = 1;i <= n;i ++)
	{
		cin >> k[i];
		for(int j = 1;j <= k[i];j ++)
		{
			cin >> a[j] >> t[j];
			add(a[j],m + i,t[j]);
			add(m + i,a[j],t[j]);
		}
	}
	while(Q --)
	{
		int x,y;
		cin >> x >> y;
		dij(x,y);
		cout << dis[y] + w[x] + w[y] << '\n';
	}
	return 0;
}
