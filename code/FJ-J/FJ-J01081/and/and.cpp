#include <iostream>
using namespace std;
int n, m, a[200005] = {}, dp[5005][5005] = {};

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	int power = 1;
	for(int i = 1; i <= 30; i++) dp[0][0] += power, power *= 2;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= i; j++)
			dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]&a[i]);
	cout << dp[n][m];
	return 0; 
}
