#include <cmath>
#include <queue>
#include <vector>
#include <cstring>
#include <iostream>
#define ll long long
#define pii pair <int, int>
using namespace std;

const int N = 5005;
int n;
ll d, a[N];
vector <int> g[N];

queue <pii> q;
int dis[N], cnt[N][N];
int vis[N];
void bfs(int sd)
{
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	q.push({sd, 0});
	dis[sd] = 0;
	
	while (q.size())
	{
		pii f = q.front();
		q.pop();
		
		if (f.second == dis[f.first])
			++cnt[sd][f.first];
		else if (f.second > dis[f.first])
			continue;
		
		for (int v : g[f.first])
		{
			if (vis[v] <= 1 && dis[f.first] + 1 <= dis[v])
			{
				++vis[v];
				dis[v] = dis[f.first] + 1;
				q.push({v, f.second + 1});
			}
		}
	}
}

void solu()
{
	int ans = 0;
	cin >> n >> d;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		g[i].clear();
	}
		
	for (int u = 1; u <= n; ++u)
	{
		for (int v = 1; v <= n; ++v)
		{
			cnt[u][v] = 0;
			cnt[v][u] = 0;
			if (u == v) continue;
			if (abs(a[u] - a[v]) <= d)
			{
				g[u].push_back(v);
				g[v].push_back(u);
			}
		}
	}
	
	for (int i = 1; i <= n; ++i)
		bfs(i);
	
	for (int u = 1; u < n; ++u)
	{
		for (int v = u + 1; v <= n; ++v)
		{
			if (cnt[u][v] == 2 && abs(u - v) >= 2)
				++ans;
		}
	}
	cout << ans / 3 << '\n';
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int dxd, T;
	cin >> dxd >> T;
	while (T--)
		solu();
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
