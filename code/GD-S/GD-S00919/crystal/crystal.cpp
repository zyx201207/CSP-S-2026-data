#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

const int N = 5e5 + 5;

int n;
ll m, a[N], sum[N];

inline ll calc(int l, int r)
{
	return a[r] * (r - l + 1) - (sum[r] - sum[l - 1]);
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++i)
	{
		sum[i] = sum[i - 1] + a[i];
	}
	int l = 1, r = 1, ans = 0;
	while (r <= n)
	{
		while (calc(l, r) > m)
			++l;
		ans = max(ans, r - l + 1);
		++r;
	}
	printf("%d\n", ans);
	return 0;
}
