#include<bits/stdc++.h>
using namespace std;

int n, m;
const int N = 1e5;
long long dp[N];
long long a[N];

int main ()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		dp[1] = max(dp[1], a[i]);
	}
	if (m == 2)
	{
		long long ans = -1;
		for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			ans = max(ans, a[i] & a[j]);
		cout << ans;
		return 0;
	}
	for (int i = 1; i <= n; i++)
	for (int j = m; j >= 1; j--) 
	{
		if (dp[j-1] != a[i])
			dp[j] = max(dp[j], dp[j-1] & a[i]);
	}
	cout << dp[m];
	
	return 0;
}
