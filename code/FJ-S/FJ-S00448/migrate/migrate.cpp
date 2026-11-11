#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
const int INF = 1e9;
struct Point
{
	long long id, dis; 
	bool operator < (const Point x) const
	{
		return dis < x.dis;
	}
}; 
long long c, t, n, d, x[MAXN], dis[MAXN], cnt[MAXN], ans;
bool flag[MAXN];
vector<int> e[MAXN];
priority_queue<Point> q; 
void init()
{
	ans = 0;
	for (int i = 1; i <= n; i++)
	{
		dis[i] = INF;
		cnt[i] = 0;
		flag[i] = false;
		e[i].clear();
	}
}
void init1()
{
	for (int i = 1; i <= n; i++)
	{
		dis[i] = INF;
		cnt[i] = 0;
		flag[i] = false;
	}
}
void dijkstra(int s)
{
	dis[s] = 0;
	q.push((Point){s, 0});
	while(!q.empty())
	{
		int u = q.top().id;
		q.pop();
		if (flag[u])
			continue;
		flag[u] = true;
		for (int i = 0; i < (int)e[u].size(); i++)
		{
			int v = e[u][i];
			if (dis[u] + 1 < dis[v])
			{
				if (cnt[v] == 2)
					ans--;
				cnt[v] = 1;
				dis[v] = dis[u] + 1;
				q.push((Point){v, dis[v]});
			}
			else if (dis[u] + 1 == dis[v])
			{
				if (cnt[v] == 1)
					ans++;
				else if (cnt[v] == 2)
					ans--;
				cnt[v]++;
			}
		} 
	}
	init1();
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		init();
		for (int i = 1; i <= n; i++)
			cin >> x[i];
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
			{
				if (x[j] - x[i] > d)
					break;
				e[i].push_back(j);
				e[j].push_back(i);
			}
		for (int i = 1; i <= n; i++)
			dijkstra(i);
		cout << ans / 2 << endl;
	}
	return 0;
}//~10
