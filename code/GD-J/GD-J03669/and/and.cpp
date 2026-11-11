#include <bits/stdc++.h>
using namespace std;
long long a[200005], dp[200005], ans;
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		dp[i] = a[i];
	}
	int t = m;
	m--;
	for (int i = n; i >= 1; i--)
	{
		if (i >= 1)
			dp[i] = max(dp[i-1] & a[i], dp[i]);
	}
	cout << dp[n] << "\n";
	
	return 0;
}
