#include <iostream>
#include <vector>


int n, m, ans;
void solve1(std::vector<int> &a, std::vector<bool> &vis, int x)
{
	if (x == n)
	{
		int am = 0;
		for (int i = 0; i < n; i++)
		{
			am += vis[i];
		}
		if (am != m) return;
		int sum = 0, cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if (vis[i])
			{
				if(cnt == 0) sum = a[i];
				cnt++;
				sum &= a[i];
			}
		}
		ans = std::max(ans, sum);
		return;
	}
	vis[x] = true;
	solve1(a, vis, x + 1);
	vis[x] = false;
	solve1(a, vis, x + 1);
}

int main()
{
	std::freopen("and.in", "r", stdin);
	std::freopen("and.out", "w", stdout);
	
	std::cin >> n >> m;
	std::vector<int> a(n);
	for (auto &i : a)
	{
		std::cin >> i;
	}
	if (n <= 20)
	{
		std::vector<bool> vis(n);
		solve1(a, vis, 0);
		std::cout << ans;
		return 0;
	}
	if (m == 1)
	{
		for (int i = 0; i < n; i++)
		{
			ans = std::max(ans, a[i]);
		}
		std::cout << ans;
		return 0;
	}
	if (m == 2)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if(i != j)
				{
					ans = std::max(ans, a[i] & a[j]);
				}
			}
		}
		std::cout << ans;
		return 0;
	}
	if (m == n)
	{
		for (int i = 0; i < n; i++)
		{
			ans &= a[i];
		}
		std::cout << ans;
		return 0;
	}
	if (m == n - 1)
	{
		int sum = 0x7fffffff;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if(i != j)
				{
					sum &= a[j];
				}
			}
			ans = std::max(ans, sum);
		}
		std::cout << ans;
		return 0;
	}
	std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0x7fffffff));
	for (int i = 1; i < n; i++)
	{
		for (int j = m; j > 0; j--)
		{
			dp[i][j] = std::max(dp[i][j], dp[i - 1][j - 1] & a[i]);
		}
	}
	std::cout << dp[n - 1][m];
}
