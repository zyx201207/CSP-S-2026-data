#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], b[500005], ans = -99999999;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++)
	{
		sort(a + 1, a + 1 + n);
		a[1]++;
	}
	for (int i = 1; i <= n; i++)
	{
		long long x = a[i];
		b[x]++;
	}
	for (int i = 1; i <= n; i++)
	{
		ans = max(b[i], ans);
	}
	cout << ans;
	return 0;
}
