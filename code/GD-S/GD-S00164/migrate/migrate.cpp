#include <stdio.h>
#include <string.h>
#define ll long long
#define ull unsigned long long
#define maxn 5010
int n;ll d, a[maxn];ull f[maxn][maxn];
int main()
{
	freopen("migrate.in", "r", stdin), freopen("migrate.out", "w", stdout);
	int T;
	scanf("%*d%d", &T);
	while (T--)
	{
		scanf("%d%lld", &n, &d);
		for (int i = 1;i <= n;i++)
			scanf("%lld", &a[i]);
		ll ans = 0;
		for (int i = 1;i <= n;i++)
		{
			memset(f, 0, sizeof f);
			f[i][0] = 1;
			for (int j = i;j <= n;j++)
			{
				int flag = 0;
				for (int t = 0;t <= n;t++)
				{
					if (f[j][t]) flag = 1;
					if (flag == 1 && !f[j][t]) break;
					for (int k = 1;j + k <= n && a[j] + d >= a[j + k];k++)
						f[j + k][t + 1] += f[j][t];
				}
			}
				
			for (int j = i + 1;j <= n;j++)
				for (int t = 0;t <= n;t++)
					if (f[j][t] != 0)
					{
						if (f[j][t] == 2) ans++;
						else break;
					}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
