#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
using namespace std;

const int M = 5e5 + 5,N = 505;
const ll inf = 4e18;
int c,n,m,d,q,w[M],t[M][N];
ll len[N][N],dis[N][N];
vector<int> v[M];
vector<pil> e[M];

void dijkstra(int rt)
{
	for(int i = 1;i <= n;i++) dis[rt][i] = inf;
	dis[rt][rt] = 0;
	priority_queue<pli,vector<pli>,greater<pli>> q;
	vector<int> vis(n + 5,0);
	q.push({dis[rt][rt],rt});
	while(!q.empty())
	{
		int u = q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(pil& tmp : e[u])
		{
			int v = tmp.first;
			ll w = tmp.second;
			if(dis[rt][v] > dis[rt][u] + w)
			{
				dis[rt][v] = dis[rt][u] + w;
				q.push({dis[rt][v],v});
			}
		}
	}
	return;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= n;i++)
		for(int j = i;j <= n;j++)
			len[i][j] = (i == j ? 0ll : inf);
	for(int i = 1;i <= n;i++)
	{
		int k;
		cin >> k;
		for(int j = 1;j <= k;j++)
		{
			int ai,ti;
			cin >> ai >> ti;
			t[ai][i] = ti;
			v[ai].push_back(i);
		}
	}
	for(int i = 1;i <= m;i++)
	{
		int k = v[i].size();
		for(int x = 0;x < k;x++)
			for(int y = x + 1;y < k;y++)
				len[v[i][x]][v[i][y]] = min(len[v[i][x]][v[i][y]],t[i][v[i][x]] * (ll)(1) + t[i][v[i][y]] * (ll)(1));
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = i + 1;j <= n;j++)
		{
			if(len[i][j] == inf) continue;
			e[i].push_back({j,len[i][j]});
			e[j].push_back({i,len[i][j]});
		}
	}
	for(int i = 1;i <= n;i++) dijkstra(i);
	while(q--)
	{
		int x,y;
		cin >> x >> y;
		ll ans = inf;
		for(int& p1 : v[x])
			for(int& p2 : v[y])
				ans = min(ans,w[x] * (ll)(1) + w[y] * (ll)(1) + t[x][p1] * (ll)(1) + t[y][p2] * (ll)(1) + dis[p1][p2]);
		cout << ans << "\n";
	}
	return 0;
}
