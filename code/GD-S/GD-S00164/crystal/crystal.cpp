#include <stdio.h>
#include <algorithm>
typedef long long ll;
constexpr int maxn = 5e5 + 10;
int n;ll m, a[maxn], sum[maxn];
int main()
{
	freopen("crystal.in", "r", stdin), freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1;i <= n;i++)
		scanf("%lld", &a[i]);
	std::sort(a + 1, a + 1 + n);
	int ans = 0;
	for (int i = 1;i <= n;i++)
	{
		sum[i] = sum[i - 1] + a[i];
		int l = 1, r = i;
		while (l <= r)
		{
			int mid = l + ((r - l) >> 1);
			if (a[i] * (i - mid + 1) - (sum[i] - sum[mid - 1]) <= m) r = mid - 1;
			else l = mid + 1;
		}
		ans = std::max(ans, i - l + 1);
	}
	printf("%d\n", ans);
	return 0;
}
