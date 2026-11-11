#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m;
int a[N];
int dp[N];
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n == m)
	{
		int ans = a[1];
		for (int i = 2; i <= n; i++) ans &= a[i];
		cout << ans;
		return 0;
	}
	if (m == 1)
	{
		int ans = a[1];
		for (int i = 2; i <= n; i++) ans = max(ans, a[i]);
		cout << ans;
		return 0;
	}
	if (m == 2)
	{
		int ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++) ans = max(ans, (a[i] & a[j]));
		cout << ans;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
