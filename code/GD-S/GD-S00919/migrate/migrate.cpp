#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e6 + 5;

int n; ll d;
ll x[N];
int suf[N], f[N], g[N];


void solve()
{
	scanf("%d%lld", &n, &d);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%lld", &x[i]);
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		suf[i] = i;
		f[i] = 0; g[i] = 1;
		for (int j = i - 1; j >= 1; --j)
		{
			suf[j] = suf[j + 1];
			while (x[suf[j]] - x[j] > d)
				--suf[j];
			if (suf[j] == j) break;
			
			f[j] = f[suf[j]] + 1; g[j] = g[suf[j]];
			
			if (j < suf[j] - 1 && f[suf[j]] == f[suf[j] - 1])
				g[j] = min(3, g[j] + g[suf[j] - 1]);
			
			if (j < suf[j] - 2 && f[suf[j]] == f[suf[j] - 2])
				g[j] = min(3, g[j] + g[suf[j] - 2]);
			
			ans += (g[j] == 2);
		}
	}
	printf("%lld\n", ans);
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int sub, T;
	scanf("%d%d", &sub, &T);
	while (T--)
	{
		solve();
	}
	return 0;
}
