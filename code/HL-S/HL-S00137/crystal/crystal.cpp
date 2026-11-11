#include <cstdio>
#include <algorithm>
using namespace std;
long long a[500001];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	//for (int i = 1; i <= n; i ++)
	//{
	//	printf("%lld\n", a[i]);
	//}
	if (n <= 5000)
	{
		long long ppp = 0;
		for (int _ = 2; _ <= n; _ ++)
		{
			long long t = 0;
			for (int i = _; i <= n; i ++)
			{
				t += (a[i] - a[i - 1]) * (i - 1 - _ + 2);
				//printf("merging %d crystal needs %d power(s) at least\n", i, t);
				if (t > m)
				{
					ppp = max(ppp, i - 1 - _ + 2ll);
					break;
				}
			}
		}
		printf("%d", ppp);
	}
	else
	{
		long long t = 0;
		for (int i = 2; i <= n; i ++)
		{
			t += (a[i] - a[i - 1]) * (i - 1);
			//printf("merging %d crystal needs %d power(s) at least\n", i, t);
			if (t > m)
			{
				printf("%d", i - 1);
				return 0;
			}
		}
		printf("%d", n);
	}
	return 0;
}