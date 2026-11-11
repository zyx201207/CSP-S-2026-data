#include<bits/stdc++.h>
using namespace std;
long long c, t;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	for (long long _ = 1; _ <= t; _++)
	{
		long long n, d;
		cin >> n >> d;
		long long x[n + 5];
		for (long long i = 1; i <= n; i++)
			cin >> x[i];
		long long ans = 0;
		for (long long i = 1; i < n; i++)
			for (long long j = i + 1; j <= n; j++)
				if (x[j] - x[i] > d && ((x[j] - x[i])) % (((x[j] - x[i]) + d - 1) / d) > 0)
				{
					bool ok = 1;
					for (int k = i; k < j; k++)
						if (x[k + 1] - x[k] > d)
						{
							ok = 0;
							break;
						}
					ans += ok;
				}
		cout << ans << endl;
	}
	return 0;
 }
