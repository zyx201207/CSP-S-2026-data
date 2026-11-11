#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m;

const int N = 5e5 + 10;

int a[N], b[N], c[N];
int s[N];
int ans[N];

signed main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = n; i; --i)
	{
		c[i] = b[a[i]];
		b[a[i]] = i;
	}
	for (int i = 1; i <= n; ++i)
	{
		++s[i];
		if (c[i])
			s[c[i]] += s[i];
		else
		{
			ans[a[i]] += s[i];
			s[i+1] += s[i];
		}
	}
	for (int i = 1; i <= m; ++i)
		cout << ans[i] << ' ';
	return 0;
}
