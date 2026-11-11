//Task3: migrate
/*
使用一维动态规划用 O(nlogn)解决 
总复杂度 
O(n^2logn)
还有写了特殊 A
预计得分 48pts 
*/
#include <bits/stdc++.h>
using namespace std;
const long long N = 2000006;
long long c, t, n, d, dp[N], cnt[N], beg, a[N], l, r, mid, ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld", &c, &t);
	if (c == 11 || c == 12)
	{
		while(t--)
		{
			scanf("%lld%lld", &n, &d);
			for (long long i = 1; i <= n; i++)
				scanf("%lld", &a[i]);
			if (a[2] - a[1] >= d)
			{
				printf("0\n");
				continue;
			}
			printf("%lld\n", max(n - d / (a[2] - a[1]) * 2 + 1, 0ll));
		}
		return 0;
	}
	while(t--)
	{
		ans = 0;
		scanf("%lld%lld", &n, &d);
		for (long long i = 1; i <= n; i++)
			scanf("%lld", &a[i]);
		a[n + 1] = 0x3f3f3f3f3f3f3f3f;
		for (long long i = 1; i <= n; i++)
		{
			for (long long j = i; j <= n; j++)
			{
				cnt[j] = 0;
				dp[j] = 0x3f3f3f3f3f3f3f3f;
			}
			cnt[i] = 1;
			dp[i] = 0;
			for (long long j = i; j <= n; j++)
			{
				l = j + 1;
				r = n + 1;
				while(l < r)
				{
					mid = (l + r) / 2;
					if (a[mid] - a[j] > d)
						r = mid;
					else
						l = mid + 1;
				}
				for (long long z = l - 1; z > j; z--)
				{
					if (dp[z] <= dp[j])
						break;
					if (dp[z] == dp[j] + 1)
						cnt[z] += cnt[j];
					else if (dp[z] > dp[j] + 1)
					{
						dp[z] = dp[j] + 1;
						cnt[z] = cnt[j];
					}
				}
			}
			for (long long j = i + 1; j <= n; j++)
				if (cnt[j] == 2)
					ans++;
		}
		printf("%lld\n", ans);
	}
}
