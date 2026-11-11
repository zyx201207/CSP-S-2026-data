#include <bits/stdc++.h>
using namespace std;
long long n,m,a[int(2e5 + 5)];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if (m == 1)
	{
		long long maxn = -100;
		for (int i = 1;i <= n;i++)
		{
			maxn = max(maxn,a[i]);
		}
		cout << maxn;
		return 0;
	}
	if (m == n)
	{
		long long ans = a[1];
		for (int i = 2;i <= n;i++)
		{
			ans &= a[i];
		}
		cout << ans;
		return 0;
	}
	if (m == 2)
	{
		long long maxn = -100;
		for (int i = 1;i <= n;i++)
		{
			for (int j = i + 1;j <= n;j++)
				maxn = max(maxn,a[i] & a[j]);
		}
		cout << maxn;
		return 0;
	}
	return 0;
}
