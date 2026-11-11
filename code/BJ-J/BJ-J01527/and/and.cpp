//55pts
#include <bits/stdc++.h>
using namespace std;

int m,n,a[200010],dp[5010][5010],maxx;

int main()
{
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	cin >> n >> m;
	if (n > 5000)
	{
		for (int i = 1;i <= n;i ++) cin >> a[i];
		sort(a + 1, a + n + 1);
		cout << a[n - m + 1];
		return 0;
	}
	if (m == n)
	{
		int ans = 0;
		for (int i = 1;i <= n;i ++) ans &= a[i];
		cout << ans;
		return 0;
	}
	for (int i = 1;i <= n;i ++)
	{
		cin >> a[i];
		dp[i][1] = a[i];
	}
	for (int i = 1;i <= n;i ++)
		for (int j = 1;j < i;j ++)
			for (int k = 2;k <= m;k ++) dp[i][k] = max(dp[i][k] , (dp[i][k - 1] & dp[j][k - 1]));
	for (int i = 1;i <= n;i ++) maxx = max(maxx , dp[i][m]);
	cout << maxx;
	return 0;
}