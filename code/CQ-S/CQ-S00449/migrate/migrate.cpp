#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

namespace wxr
{

const int maxn = 5000 + 10;

long long a[maxn];

std::pair<long long, long long> f[maxn][maxn];

void update(std::pair<long long, long long> &x, std::pair<long long, long long> y, std::pair<long long, long long> z)
{
	y.first += z.first, y.second *= z.second;
	if (x.first > y.first) x = y;
	else if (x.first == y.first) x.second += y.second;
}


int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int Case, T;
	scanf("%d %d", &Case, &T);
	while (T--)
	{
		int n; long long k;
		scanf("%d %lld", &n, &k);
		for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
		
//		for (int i = 1; i <= n; i++)
//		{
//			for (int j = 1; j <= n; j++)
//			{
//				if (j <= i) printf("  ");
//				else
//				{
//					if (a[j] - a[i] > k)
//					{
//						int cnt = 0;
//						for (int t = i + 1; t <= j - 1; t++)
//						{
//							if (a[t] - a[i] <= k && a[j] - a[t] <= k) cnt++;
//						}
//						if (cnt == 2)
//						{
//							printf("1 ");
//						}
//						else printf("0 ");
//					}
//					else printf("0 ");
//				}
//			}
//			printf("\n");
//		}
//		printf("\n");
//		
//		continue;
		
		long long ans = 0;
		
		for (int st = n; st >= 1; st--)
		{
			for (int i = st + 1; i <= n; i++)
			{
				f[st][i] = {1LL << 60, 0};
				for (int j = st; j < i; j++)
				{
					if (a[i] - a[j] <= k)
					{
						if (j == st) update(f[st][i], {0, 1}, {1, 1});
						else update(f[st][i], f[st][j], f[j][i]);
					}
				}
				if (f[st][i].second == 2) ans++;
			}
		}
		
		printf("%lld\n", ans);
		
//		for (int i = 1; i <= n; i++)
//		{
//			for (int j = 1; j <= n; j++)
//			{
//				if (j <= i) printf("  ");
//				else printf("%lld ", f[i][j].second);
//				continue;
//			}
//			printf("\n");
//		}
//		printf("\n");
	}
	return 0;
}
}

int main()
{
	wxr::main();
	return 0;
}

