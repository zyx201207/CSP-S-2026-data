#include <bits/stdc++.h>
using namespace std;
const int N = 2003;
int n,m,ans,sum,a[N],dp[N][N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;dp[i][1] = a[i],i++) cin >> a[i];
	if (m == n)
	{
		for (int i = 1;i <= n;i++) ans &= a[i];
		cout << ans << "\n";
		return 0;
	}
	else if (m == n - 1)
	{
		for (int i = 1;i <= n;i++) sum &= a[i];
		for (int i = 1;i <= n;i++) ans = max(ans,(sum & a[i]));
		cout << ans << "\n";
	}
	else
	{
		for (int i = 1;i <= n;i++) for (int j = 2;j <= m;j++) for (int l = 1;l < i;l++) dp[i][j] = max(dp[i][j],(dp[l][j - 1] & a[i]));
		for (int i = 1;i <= n;i++) ans = max(ans,dp[i][m]);
		cout << ans << "\n";
	}
	return 0;
}
