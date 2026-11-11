#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, a[N], pian_ans, ans;
bool flag, cb, vis[N];
bool check_A(int x)
{
	int cnt = 1;
	while (cnt * cnt <= n)
	{
		cnt++;
		if (cnt * cnt == n)return 1;
	}
	return 0;
}

void dfs(int x, int cnt, int p)
{
	if (cnt > m)
	{
		//cout << ans << '\n';
		ans = max(ans, p);
		return;
	}
	//if (vis[x] == 1)return;
	
	for(int i = 1; i <= n; i++)
	{
		//if(i == x)continue;
		if (!vis[i])
		{
			vis[i] = 1;
			if (p == 0)dfs(i, cnt + 1, a[i]);
			else dfs(i, cnt + 1, p & a[i]);
			vis[i] = 0;
		}
	}
}
signed main ()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (!check_A(a[i] + 1))flag = 1;
	}
	if (m == 1)
	{
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			ans = max(ans, a[i]);
		}
		cout << ans;
		return 0;
	}
	if (m == n)
	{
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			if (i == 1)ans = a[i];
			else ans = (ans & a[i]);
		}
		cout << ans;
		return 0;
	}
	if (m == 2)
	{
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			int k = a[i];
			for (int j = 1; j <= n; j++)
			{
				if (i == j)continue;
				ans = max(ans, a[i] & a[j]);
			}
		}
		cout << ans;
		return 0;
	}
	
	if (n <= 20)
	{
		dfs(1, 1, 0);
		cout << ans;
		return 0;		
	}
	sort(a + 1, a + 1 + n, greater<int>());
	if (flag == 0)
	{
		cout << a[m];
		return 0;
	}
	dfs(1, 1, 0);
	cout << ans;
	return 0;
}
/*

4 2
3 15 12 12



3 2
3 7 15

5 3
31 3 1 15 7

1 10 11

0011
1111
1100
1110




*/
