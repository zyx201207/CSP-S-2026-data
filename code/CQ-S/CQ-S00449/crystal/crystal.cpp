#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

namespace wxr
{

const int maxn = 5e5 + 10;

long long a[maxn], s[maxn];

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n; long long m;
	scanf("%d %lld", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	std::sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int L = 1, R = i;
		while (L < R)
		{
			int k = (L + R) / 2;
			if (a[i] * (i - k + 1) - (s[i] - s[k - 1]) <= m) R = k;
			else L = k + 1;
		}
		ans = std::max(ans, i - L + 1);
	}
	
	printf("%d\n", ans);
	return 0;
}
}

int main()
{
	wxr::main();
	return 0;
}

