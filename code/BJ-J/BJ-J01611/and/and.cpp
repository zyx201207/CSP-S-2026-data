#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	int n, m;
	static unsigned int a[200001];
	static unsigned int dp[200001];
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	
	sort(a + 1, a + n + 1, greater<unsigned int>());
	
	for (int i = 1; i <= n; ++i)
	{
		for (int j = m; j >= 2; --j)
		{
			dp[j] = max(dp[j], (dp[j - 1] & a[i]));
		}
		dp[1] = a[i];
	}
	
	cout << dp[m] << '\n';
	
	return 0;
}
