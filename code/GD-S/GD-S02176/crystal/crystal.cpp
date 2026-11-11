#include <stdio.h>
#include <algorithm>
using namespace std;
using i64 = long long;
const int N = 5e5 + 1;
i64 a[N], sum[N];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	i64 m;
	scanf("%d%lld", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i)
		sum[i] = sum[i-1] + a[i];
	int x = 1, y = 1, ans = 0;
	while(y <= n)
	{
		const i64 res = a[y] * (y - x) - sum[y-1] + sum[x-1];
		if(res <= m)
		{
			ans = max(ans, y - x + 1);
			++y;
		}
		else
			++x;
	}
	printf("%d\n", ans);
	return 0;
}
