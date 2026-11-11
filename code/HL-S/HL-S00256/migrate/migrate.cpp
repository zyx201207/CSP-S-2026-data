#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 10010;
int n, d;
int a[N];
int to[N];
bool st[N];
int dis[N], cnt[N];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >  q;
void dijk(int sta)
{
	memset(dis, 0x3f, sizeof dis);
	memset(cnt, 0, sizeof cnt);
	memset(st, 0, sizeof st);
	q.push({0, sta});
	dis[sta] = 0;
	cnt[sta] = 1;
	while (!q.empty())
	{
		pair<int, int> t = q.top(); q.pop();
		st[t.second] = 1;
		if (dis[to[t.second]] > dis[t.second] + 1)
		{
			dis[to[t.second]] = dis[t.second] + 1;
			
			cnt[to[t.second]] = cnt[t.second];
			if (!st[to[t.second]])
			{
				q.push({ dis[to[t.second]], to[t.second] });
			}
		}
		else if (dis[to[t.second]] == dis[t.second] + 1)
		{
			cnt[to[t.second]] += cnt[t.second];
		}
		if (t.second != sta)
		{
			if (dis[t.second - 1] > dis[t.second])
			{
				
				dis[t.second - 1] = dis[t.second];
				cnt[t.second - 1] = cnt[t.second];
				if (!st[t.second - 1])
				{
					q.push({ dis[t.second - 1], t.second - 1 });
				}
			}
			else if (dis[t.second - 1] == dis[t.second])
			{
				cnt[t.second - 1] += cnt[t.second];
			}
		}
		
	}
}

void solve()
{
	cin >> n >> d;
	for (int i = 1; i <= n; i ++ )
	{
		cin >> a[i];
	}
	int r = 1;
	for (int i = 1; i <= n; i ++ )
	{
		while (r <= n && a[r] - a[i] <= d) r ++ ;
		to[i] = r - 1;
	}
	int ans = 0; 
	for (int i = 1; i <= n; i ++ )
	{
		dijk(i);
		for (int j = i + 1; j <= n; j ++ )
		{
//			cout << cnt[j] << ' ' ;
			if (cnt[j] == 2) ans ++ ;
		}
//		cout << '\n';
	}
	cout<< ans << '\n';
	return ;
}
signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int c, t;
	cin >> c >> t;
	while (t -- )
		solve();
	return 0;
}

