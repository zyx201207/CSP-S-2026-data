#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 5e3 + 5, INF = 1e18;
int c, t, n, d, x[N], dis[N][N], cnt[N][N], ans;
void bfs(int st)
{
	queue <int> q;
	q.push(st);
	dis[st][st] = 0;
	cnt[st][st] = 1;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int v = u + 1; v <= n; v++)
		{
			if (x[v] - x[u] > d) break;
			int cur = dis[st][u] + 1;
			if (cur < dis[st][v])
			{
				dis[st][v] = cur;
				cnt[st][v] = 1;
				q.push(v);
			}
			else if (cur == dis[st][v])
			{
				cnt[st][v]++;
			}
		}
	}
	for (int i = st+1; i <= n; i++)
		if (cnt[st][i] == 2)
		{
			//cout << st << ' ' << i << endl;
		    ans++;
		}
	return;
}
void solve()
{
	ans = 0;
	cin >> n >> d;
	for (int i = 1; i <= n; i++)
	    for (int j = 1; j <= n; j++)
        {
        	cnt[i][j] = 0;
        	dis[i][j] = INF;
		}
	for (int i = 1; i <= n; i++)
	{
		cin >> x[i];
	}
	for (int i = 1; i <= n; i++)
	    bfs(i);
	cout<< ans<< endl;
	return;
}
signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while (t--) solve();
	return 0;
}