#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5e5 + 8;
int n;
ll m;
ll a[N];
ll sum[N], suf[N];

ll get_sum(int l, int r)
{
	if (l > r)
		return 0;
	return sum[r] - sum[l - 1];
}

int get_cnt(int l, int r)
{
	if (l > r)
		return 0;
	return r - l + 1;
}

bool check(int l, int r)
{
	ll val = a[l] * get_cnt(l, r) - get_sum(l, r);
	return val <= m;
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + 1 + n, greater<ll>());
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	int ans = 0;
	for (int l = 1, r = 1; l <= n; l++)
	{
		while (r < n && check(l, r + 1))
		{
			++r;
		}
		ans = max(ans, r - l + 1);
	}
	printf("%d\n", ans);
	return 0;
}