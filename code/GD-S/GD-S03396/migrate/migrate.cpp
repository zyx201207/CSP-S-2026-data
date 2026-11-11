#include <bits/stdc++.h>
using namespace std;
long long c, t;
long long x[2000010];
long long f[2000010];
long long g[2000010];
long long s[2000010];
long long l[2000010];
long long fr[2000010];
void work1()
{
	while (t--)
	{
		long long n, d;
		scanf("%lld %lld", &n, &d);
		for (int i = 1; i <= n; i++)
			scanf("%lld", &x[i]);
		l[n + 1] = n;
		for (int i = n; i >= 1; i--)
		{
			l[i] = l[i + 1];
			while (l[i] > 1 && x[i] - x[l[i] - 1] <= d)
				l[i]--;
		}
		long long ans = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				f[j] = 1e9;
				g[j] = 0;
				fr[j] = 0;
			}
			f[i] = 0;
			g[i] = 1;
			fr[0] = 1;
			s[i] = 1;
			s[i - 1] = 0;
			for (int j = i + 1; j <= n; j++)
			{
				if (l[j] == j)
					break;
				f[j] = f[max(l[j], (long long)i)] + 1; 
				if (fr[f[j]] == 0) fr[f[j]] = j;
				g[j] = s[fr[f[j]] - 1] - s[max(l[j], (long long)i) - 1];
				s[j] = s[j - 1] + g[j];
				if (g[j] == 2)
					ans++;
			}
		}
		printf("%lld\n", ans);
	}
}
void work2()
{
	while (t--)
	{
		long long n, d;
		scanf("%lld %lld", &n, &d);
		for (int i = 1; i <= n; i++)
			scanf("%lld", &x[i]);
		if (n == 1)
		{
			printf("0\n");
			continue;
		}
		long long de = x[2] - x[1];
		if (d < 2 * de)
		{
			printf("0\n");
			continue;
		}
		printf("%lld\n", max(n - 2*(d / de) + 1, 0ll));
	}
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%lld %lld", &c, &t);
	if (c <= 10)work1();
	if (11 <= c && c <= 12) work2(); 
	return 0;
}
