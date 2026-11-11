#include <iostream>
#include <algorithm>
using namespace std;

const int N = 5e5 + 10;

long long d[N], nm[N], m, z;

int q[N], n, ans, s, k, cnt = 1;

int l = 1;

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", d + i);
	}
	sort(d + 1, d + 1 + n);
	d[n + 1] = d[n] + 1;
	for (int i = 1; i <= n; i++)
	{
		if (d[i] != d[i + 1])
		{
			q[cnt]++;
			long long r = ((i - q[cnt] + 1 - l) * (d[i] - d[i - q[cnt]]));
			while (l <= i && m < (z + r))
			{
				z -= (d[i - q[cnt]] - d[l]);
				l++;
				r = ((i - q[cnt] + 1 - l) * (d[i] - d[i - q[cnt]]));
			}
			z += r;
			if (m >= z)
			{
				ans = max(ans, (i - l + 1));
			}
//			printf("%d %lld %d\n", ans, z, l);
//			s = q[cnt], k = cnt - 1, z = m;
//			while (k > 0 && z)
//			{
//				long long w = d[i] - nm[k];
//				if (z < w)
//				{
//					break;
//				}
//				w = z / w;
//				s += min(w, 1ll * q[k]);
//				z -= min(w, 1ll * q[k]) * (d[i] - nm[k]);
//				k--;
//			}
//			ans = max(ans, s);
//			printf("%d %d\n", ans, s);
//			nm[cnt] = d[i];
			++cnt;
		}
		else
		{
			q[cnt]++;
		}
	}
	printf("%d", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/
