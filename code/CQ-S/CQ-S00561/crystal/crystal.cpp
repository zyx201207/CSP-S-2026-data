#include <stdio.h>
#include <algorithm>
void setmax(int& x, int y) { if (x < y) x = y; }
constexpr int N = 500000;
int n;
long long m, a[N + 5];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", a + i);
	std::sort(a + 1, a + n + 1);

	int ans = 1;
	long long sum = 0;
	for (int l = 1, r = 1; r <= n; ++r)
	{
		while (sum > m)
		{
			sum -= a[r] - a[l];
			++l;
		}
		setmax(ans, r - l + 1);
		sum += (a[r + 1] - a[r]) * (r - l + 1);
	}
	printf("%d\n", ans);
	return 0;
}

// 14 : 42