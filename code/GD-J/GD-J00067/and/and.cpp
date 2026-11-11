#include<bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 10;

int m, n, dp[maxn], a[maxn];

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> n >> m;
	
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	
	for (int j = m;j >= 1;j--)
	{
		dp[j] = max(INT_MAX & a[1], dp[j]);
	}
	
	for (int i = 1;i <= m;i++)
	{
		cout << dp[i] << " ";
	}cout << '\n';
	
	for (int i = 2;i <= n;i++)
	{
		for (int j = m;j >= 1;j--)
		{
			dp[j] = max(dp[j - 1] & a[i], dp[j]);
		}
		
		for (int i = 1;i <= m;i++)
		{
			cout << dp[i] << " ";
		}cout << '\n';
	}
	
	cout << dp[m];
	
	return 0;
}
