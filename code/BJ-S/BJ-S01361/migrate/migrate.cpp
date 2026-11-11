#include <iostream>
#include <vector>
using namespace std;

const int N = 2000010;
long long x[N], dx[N];
int dp[N];

int main()
{
	ios::sync_with_stdio(false);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	int n, lstp, lstlstp;
	long long d, sum, ans;
	cout << c << endl;
	while (t--)
	{
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> x[i];
		for (int i = 2; i <= n; i++) dx[i] = x[i] - x[i - 1];
		dx[1] = 0, ans = 0;
		if (c == 11 || c == 12)
		{
			sum = 0, dp[1] = 1, lstp = lstlstp = 1;
			for (int j = 2; j <= n; j++)
			{
				sum += dx[j];
				if (sum > d)
				{
					if (dx[j] > d) break;
					sum = dx[j];
					lstlstp = lstp;
					lstp = j - 1;
					if (dp[lstp] == 3) break;
				}
				dp[j] = dp[lstp];
				if (lstp - lstlstp > 1 && sum + dx[lstp] <= d) dp[j] += dp[lstp - 1];
				if (lstp - lstlstp > 2 && sum + dx[lstp] + dx[lstp - 1] <= d) dp[j] += dp[lstp - 2];
				dp[j] = min(dp[j], 3);
				if (dp[j] == 2) ans += n - j + 1;
			}
			cout << ans << endl;
			continue;
		}
		for (int i = 1; i <= n; i++)
		{
			sum = 0, dp[i] = 1, lstp = lstlstp = i;
			for (int j = i + 1; j <= n; j++)
			{
				sum += dx[j];
				if (sum > d)
				{
					if (dx[j] > d) break;
					sum = dx[j];
					lstlstp = lstp;
					lstp = j - 1;
					if (dp[lstp] == 3) break;
				}
				dp[j] = dp[lstp];
				if (lstp - lstlstp > 1 && sum + dx[lstp] <= d) dp[j] += dp[lstp - 1];
				if (lstp - lstlstp > 2 && sum + dx[lstp] + dx[lstp - 1] <= d) dp[j] += dp[lstp - 2];
				dp[j] = min(dp[j], 3);
				if (dp[j] == 2) ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}