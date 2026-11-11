#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define ull unsigned long long

ll c, t;
ull dis[5005] = {}; // i ~ i + 1的距离 
ll n, d;

ll dfs(ll l, ll r, ll step)
{
	if (l == r) return step;
	ll p;
	ll ldis = 0;
	for (p = l; p < r; p++)
	{
		if (ldis + dis[p] <= d)
		{
			ldis += dis[p];
		}
		else 
		{
			break;
		}
	}
	if (p == l) return -1;
	else return dfs(p, r, step + 1);
}

ll dfs2(ll l, ll r, ll step, ll limit_step)
{
	if (step > limit_step) return 0;
	if (l == r)
	{
		if (step == limit_step) return 1;
		else return 0;
	} 
	ll p;
	ll ldis = 0;
	ll res = 0;
	for (p = l; p < r; p++)
	{
		if (ldis + dis[p] <= d)
		{
			ldis += dis[p];
			res += dfs2(p + 1, r, step + 1, limit_step);
		}
		else 
		{
			break;
		}
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--)
	{
		ll lst[5005] = {};
		
		
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
		{
			cin >> lst[i];
		}
		for (int i = 1; i < n; i++)
		{
			if (lst[i] < 0 && lst[i + 1] > 0) dis[i] = (ull)(-1 * lst[i]) + (ull)(lst[i + 1]);
			else dis[i] = (ull)(lst[i + 1] - lst[i]);
		}
		
//		for (int i = 1; i < n; i++) cout << dis[i] << ' ';
//		cout << '\n';
		
		ll ans = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				// 往前跳
				ll step = dfs(i, j, 0);
//				cout << "从" << i << "跳到" << j << ": " << step << '\n';
				if (step == -1) continue;
				ll tmp = dfs2(i, j, 0, step);
//				cout << tmp << '\n';
				if (tmp == 2) ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/

