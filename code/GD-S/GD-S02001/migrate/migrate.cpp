#include <bits/stdc++.h>
using namespace std;

int ccc, ttt, n, jl[2000005], jr[2000005];
long long x[2000005], d, sum, l[2000005], r[2000005];

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &ccc, &ttt);
	while (ttt--)
	{
		scanf("%d%lld", &n, &d);
		for (int i = 1; i <= n; i++)
		{
			scanf("%lld", &x[i]);
			l[i] = r[i] = 1;
			jl[i] = jr[i] = 0;
		}
		for (int i = 1; i <= n; i++)
		{
			jr[i] = max(jr[i - 1], i);
			while (x[jr[i] + 1] - x[i] <= d && jr[i] + 1 <= n)
			{
				jr[i]++;
			}
		}
		jl[n + 1] = n + 1;
		for (int i = n; i >= 1; i--)
		{
			jl[i] = min(jl[i + 1], i);
			while (x[i] - x[jl[i] - 1] <= d && jl[i] - 1 >= 1)
			{
				jl[i]--;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (jr[i] == i) continue;
			if (l[jr[i]] == 1) l[jr[i]] += l[i];
			else l[jr[i]] += 1;
		}
		for (int i = n; i >= 1; i--)
		{
			if (jl[i] == i) continue;
			if (r[jl[i]] == 1) r[jl[i]] += r[i];
			else r[jl[i]] += 1;
		}
		sum = 0;
		for (int i = 1; i <= n; i++)
		{
			if (jl[i + 1] >= i || jr[i] <= i + 1) continue;
			sum += 1ll * (l[i + 1] - 1) * (r[i] - 1);
		}
		printf("%lld\n", sum);
	}
	return 0;
}
