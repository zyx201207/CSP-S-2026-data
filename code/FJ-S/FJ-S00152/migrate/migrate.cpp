#include <bits/stdc++.h>
using namespace std;

int dist[2000010],cnt[2000010];
int a[2000010];
vector<int> g[2000010];

void bfs(int s)
{
	queue<int> q;
	q.push(s);
	memset(dist,0x3f,sizeof dist);
	memset(cnt,0,sizeof cnt);
	dist[s] = 0;
	cnt[s] = 1;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int v : g[u])
		{
			if (dist[v] > dist[u] + 1)
			{
				dist[v] = dist[u] + 1;
				cnt[v] = cnt[u];
				q.push(v);
			}
			else if (dist[v] == dist[u] + 1)
			{
				cnt[v] += cnt[u];
			}
		}
	}
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	cin >> T;
	while (T--)
	{
		int n,k;
		cin >> n >> k;
		for (int i = 1;i <= n;i++)
		{
			cin >> a[i];
			g[i].clear();
		}
		for (int i = 1;i <= n;i++)
		{
			for (int j = i + 1;j <= n && a[j] - a[i] <= k;j++)
			{
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
		int ans = 0;
		for (int i = 1;i <= n;i++)
		{
			bfs(i);
			for (int j = i + 1;j <= n;j++)
			{
				if (cnt[j] == 2) ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
