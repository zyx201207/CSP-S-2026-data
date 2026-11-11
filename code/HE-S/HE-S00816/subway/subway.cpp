#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 510;
int c,n,m,d,q;
ll dis[N * 3];
int head[N * 3],to[100010],nxt[100010],w[100010],tot;
bool vis[N];
void add(int x,int y,int k) {to[tot] = y,nxt[tot] = head[x],w[tot] = k,head[x] = tot ++;}
void dij(int s)
{
	priority_queue<pair<ll,int> > q;
	for(int i = 1;i <= 3 * n;++ i) dis[i] = INT_MAX,vis[i] = 0;
	dis[s] = 0;
	q.push({0,s});
	while(!q.empty())
	{
		int u = q.top().second;q.pop();
		if(vis[u]) continue;
		for(int i = head[u];~i;i = nxt[i])
		{
			int v = to[i];
			if(dis[v] > dis[u] + w[i])
			{
				dis[v] = dis[u] + w[i];
				q.push({-dis[v],v});
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
	memset(head,-1,sizeof head);
	tot = 0;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1,w;i <= m;++ i) cin >> w,add(i,i + n,w),add(i + n,i,w);
	for(int i = 1,k;i <= n;++ i)
	{
		cin >> k;
		for(int j = 1,a,t;j <= k;++ j)
		{
			cin >> a >> t;
			add(i + n,a + 2 * n,t);
			add(i + n,a + 2 * n,t);
		}
	}
	int x,y;
	while(q --)
	{
		cin >> x >> y;
		dij(x);
		cout << dis[y] << "\n";
	}
	return 0;
}

