#include <bits/stdc++.h>
using namespace std;
int n, m, a[1000000], ans, num[1000000], used[1000000], d;
void dfs(int u)
{
	if (u > m)
	{
		int d = used[1];
		for (int i = 2; i <= m; i++)
		{
			d = d & used[i];
		}
		ans = max(ans, d);
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!num[i])
		{
			num[i] = 1;
			used[u] = a[i];
			dfs(u + 1);
			num[i] = 0;
			used[u] = 0;
		}
	}
}
int main()
{
	freopen("and1.in", "r", stdin);
	freopen("and1.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	dfs(1);
	cout << ans;
	return 0;
}
