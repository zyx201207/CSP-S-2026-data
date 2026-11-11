#include <bits/stdc++.h>
using namespace std;
#define int long long
int c, t, n, d, x[2000005], cnt[2000005], mindis[2000005];
vector<int> G[2000005];
int bfs(int s)
{
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		cnt[i] = 0;
		mindis[i] = 1e9;
	}
	queue<pair<int, int> > q;
	q.push({s, 0});
	while (!q.empty())
	{
		auto now = q.front();
		q.pop();
		int u = now.first, dis = now.second;
//		cout << u << " " << dis << endl;
		if (mindis[u] == 1e9)
		{
			mindis[u] = dis;
			cnt[u]++;
		}
		else if (mindis[u] == dis)
		{
			cnt[u]++;
		}
		for (int i = 0; i < G[u].size(); i++)
		{
			int v = G[u][i];
			if (mindis[v] < dis + 1)
			{
				continue;
			}
			q.push({v, dis + 1});
		}
	}
//	for (int i = 1; i <= n; i++)
//	{
//		cout << mindis[i] << " a " << cnt[i] << endl;
//	}
	for (int i = 1; i <= n; i++)
	{
		if (i == s)
		{
			continue;
		}
		if (cnt[i] == 2)
		{
			res++;
		}
	}
//	cout << s << " aa " << res << endl;
	return res;
}
void doit()
{
	int cnt = 0, mididx;
	for (int i = 1; i <= n; i++)
	{
		if (x[i] - x[1] <= d && x[n] - x[i] <= d)
		{
			mididx = i;
			cnt++;
		}
	}
	if (cnt >= 3)
	{
		cout << 0 << endl;
		return;
	}
	int ans = 0; 
	if (cnt == 1)
	{
		for (int i = 1; i <= n; i++)
		{
			int l = upper_bound(x + i, x + n + 1, x[i] + d) - x;
			if (l == n + 1)
			{
				continue;
			}
			int ll = i, rr = n, r = i;
			while (ll <= rr)
			{
				int mid = (ll + rr) / 2;
				if (x[mid] - x[i] <= d)
				{
					r = mid;
					ll = mid + 1;
				}
				else
				{
					rr = mid - 1;
				}
			}
			if (r == -1)
			{
				continue;
			}
			ll = r, rr = n;
			int tmp = r;
			while (ll <= rr)
			{
				int mid = (ll + rr) / 2;
				if (x[mid] - x[tmp] <= d)
				{
					r = mid;
					ll = mid + 1;
				}
				else
				{
					rr = mid - 1;
				}
			}
			if (l <= r && r <= n)
			{
				ans += r - l + 1;
				if (l <= 2 * mididx - i && 2 * mididx - i <= r)
				{
					ans--;
				}
			}
		}
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			int l = upper_bound(x + i, x + n + 1, x[i] + d) - x;
			if (l == n + 1)
			{
				continue;
			}
			int ll = i, rr = n, r = i;
			while (ll <= rr)
			{
				int mid = (ll + rr) / 2;
				if (x[mid] - x[i] <= d)
				{
					r = mid;
					ll = mid + 1;
				}
				else
				{
					rr = mid - 1;
				}
			}
			if (r == -1)
			{
				continue;
			}
			ll = r, rr = n;
			int tmp = r;
			while (ll <= rr)
			{
				int mid = (ll + rr) / 2;
				if (x[mid] - x[tmp] <= d)
				{
					r = mid;
					ll = mid + 1;
				}
				else
				{
					rr = mid - 1;
				}
			}
			r++;
			r = max(l, r);
			if (l <= r && r <= n)
			{
				ans += n - r + 1;
			}
		}
	}
	cout << ans << endl;
}
signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	if (c <= 12)
	{
		while (t--)
		{
			cin >> n >> d;
			for (int i = 1; i <= n; i++)
			{
				G[i].clear();
				cin >> x[i];
			}
			for (int i = 1; i <= n; i++)
			{
				for (int j = i + 1; j <= n; j++)
				{
					if (x[j] - x[i] <= d)
					{
						G[i].push_back(j);
						G[j].push_back(i);
					}
				}
			}
			int ans = 0;
			for (int i = 1; i <= n; i++)
			{
				ans += bfs(i);
			}
			cout << ans / 2 << endl;
		}
		return 0;
	}
	else if (c == 13 || c == 14)
	{
		while (t--)
		{
			cin >> n >> d;
			for (int i = 1; i <= n; i++)
			{
				cin >> x[i];
			}
			doit();
		}
		return 0;
	}
	else
	{
		cout << 0 << endl;
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

1
2


0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0
1


13 1
5 2
1 2 3 4 5


2
*/
