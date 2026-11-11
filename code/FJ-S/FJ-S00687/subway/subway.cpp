#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll,int>;
const int N = 505;
const int M = 5e5 + 5;

vector<pii> G[N+M];
int c, n, m, d, Q;
ll T = -1;
ll w[M];

// baoli
ll dis[1005][1550];
priority_queue<pii, vector<pii>, greater<pii> > q;
void dij(int s)
{
	dis[s][s] = 0; 
	q.push({0, s});
	while (!q.empty())
	{
		pii x = q.top(); q.pop();
//		cout << x.second << '\n';
		ll d = x.first, u = x.second;
		if (d > dis[s][u]) continue;
		for (pii v : G[u])
		{
			if (dis[s][v.second] > dis[s][u] + v.first)
			{
				dis[s][v.second] = dis[s][u] + v.first;
				q.push({dis[s][v.second], v.second});
			}
		}
	}
}


void baoli()
{
	memset(dis, 0x3f, sizeof dis);
//	for (int i = 1; i <= m; i++) dij(i);
	for (int i = 1, x, y; i <= Q; i++)
	{
		cin >> x >> y;
		dij(x);
		cout << w[x] + dis[x][y] + w[y] << '\n'; 
	}
}

ll di[20000 + 500 + 5];
ll dij2(int s, int t)
{
	di[s] = 0; 
	q.push({0, s});
	while (!q.empty())
	{
		pii x = q.top(); q.pop();
//		cout << x.second << '\n';
		ll d = x.first, u = x.second;
		if (d > di[u]) continue;
		for (pii v : G[u])
		{
			if (di[v.second] > di[u] + v.first)
			{
				di[v.second] = di[u] + v.first;
				q.push({di[v.second], v.second});
			}
		}
	}
	return di[t];
}
void baoli2()
{
	for (int i = 1, x, y; i <= Q; i++)
	{
		cin >> x >> y;
		memset(di, 0x3f, sizeof di);
		cout << w[x] + dij2(x, y) + w[y] << '\n';
	}
}

int dii[3][M + 5];
void dij3(int s)
{
	
	dii[s-m][s] = 0; 
	q.push({0, s});
	while (!q.empty())
	{
		pii x = q.top(); q.pop();
//		cout << x.second << '\n';
		ll d = x.first, u = x.second;
		if (d > dii[s-m][u]) continue;
		for (pii v : G[u])
		{
			if (dii[s-m][v.second] > dii[s-m][u] + v.first)
			{
				dii[s-m][v.second] = dii[s-m][u] + v.first;
				q.push({dii[s-m][v.second], v.second});
			}
		}
	}
}
void zj()
{
	memset(dii, 0x3f, sizeof dii);
	for (int i = 1; i <= n; i++)
	{
		dij3(i+m);
//		for (int j = 1; j <= m; j++)
//		{
//			cout << dii[i][j] << ' ';
//		}
//		cout << '\n';
	 } 
	for (int i = 1, x, y; i <= Q; i++)
	{
		 cin >> x >> y;
		 ll ans = 0x3f3f3f3f3f3f3f3f;
		for (pii z : G[x])
		{
			ans = min(ans, z.first + dii[z.second-m][y]); 	
//			cout << z.first << ' ' << dii[z.second-m][y] << '\n';
		}
//		cout << ans << '\n';
		cout << w[x] + ans + w[y] << '\n';
	 } 
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> c >> n >> m >> d >> Q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	
	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++)
		{
			int a, t;
			cin >> a >> t;
			G[a].push_back({t, m + i});
			G[m + i].push_back({t, a});
		}
	}
	
	if (m <= 1000)
	{
		baoli();
		return 0;
	 } 
	
	if (n == 2)
	{
		zj();
		return 0;
	}
	baoli2();
	
	
	
	return 0;
 }

