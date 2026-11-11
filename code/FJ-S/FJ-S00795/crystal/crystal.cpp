#include <bits/stdc++.h>

#define N ((int) 5e5)

int n;
long long m, a[N + 1];

long long s[N + 1];

int ans = 1;

main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	scanf("%d %lld", &n, &m);
	for (int i = n; i; i--) scanf("%lld", &a[i]);

	std::sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];

	for (int i = n; i; i--) {
		int l = 1, r = i, mid;
		while (l < r) {
			mid = l + r >> 1;
			a[i] * (i - mid + 1) - (s[i] - s[mid - 1]) <= m ? (r = mid) : (l = mid + 1);
		}

		ans = std::max(ans, i - r + 1);
	}

	printf("%d\n", ans);
	return 0;
}