#include <bits/stdc++.h>
using namespace std;
map<int, bool> mp;
struct node
{
	int lose, num;
} a[200005];
int n, m, pre[200005];
bool cmp(node a, node b)
{
	return a.lose < b.lose;
}
int dfsans = 0;
void dfs(int num, int deep, int i)
{
	if (deep == m)
	{
		dfsans = max(num, dfsans);
		return;
	}
	if (i >= n)
	{
		return;
	}
	dfs(num, deep, i + 1);
	dfs(num & a[i + 1].num, deep + 1, i + 1);
	return;
}
bool cmp1(node a, node b)
{
	return a.num > b.num;
}
bool cmp2(node a, node b)
{
	if (a.num == 3)
		return 1;
	if (a.num == 1 && b.num == 2)
		return 1;
	return 0;
}
bool cmp3(node a, node b)
{
	return a.lose > b.lose;
}
void solve()
{
	int dp[200005][m + 1];
	for (int i = 1; i <= n; i++)
	{
		dp[i][1] = a[i].num;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] & a[i].num);
		}
	}
	cout << dp[n][m];
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	int mx_num = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].num;
		mx_num = max(mx_num, a[i].num);
		//		cout << a[i].num;
		pre[i] = pre[i - 1] & a[i].num;
		a[i].lose = pre[i - 1] - pre[i];
	}
	if (n <= 20)
	{
		int x = 1;
		for (int i = 1; i <= 21; i++)
			x *= 2;
		dfs(x - 1, 0, 0);
		cout << dfsans;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if (m == n)
	{
		cout << pre[n];
	}
	else if (m == 1)
	{
		sort(a + 1, a + 1 + n, cmp1);
		cout << a[1].num;
	}
	else if (m == 2 && n <= 3000)
	{
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				ans = max(ans, a[i].num & a[j].num);
			}
		}
		cout << ans;
	}
	else
	{
		if (mx_num <= 4)
		{
			sort(a + 1, a + 1 + n, cmp2);
			int ans = 7;
			for (int i = 1; i <= n; i++)
			{
				ans = ans & a[i].num;
			}
			cout << ans;
			return 0;
		}
		solve();
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
