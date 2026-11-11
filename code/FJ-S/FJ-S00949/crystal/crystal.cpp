#include <iostream>
#include <algorithm>
using namespace std;
int n, ans = -1e9;
long long m, a[500005];
long long d[500005], s[500005];
int n1[500005];
bool f1 = true, f2 = true;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] != i)
			f1 = false;
		if (i >= 3)
			if (a[i]-a[i-1] != a[i-1]-a[i-2])
				f2 = false;
	}
	if (f1)
	{
		for (int i = 1; i <= n; i++)
		{
			n1[i] = n1[i-1]+i;
		}
		for (int i = 1; i <= n; i++)
		{
			if (n1[i+1]>m)
			{
				cout << min(n, i+1);
				return 0;
			}
		}
		cout << n;
		return 0;
	}
	else if (f2)
	{
		long long c = a[2] - a[1];
		for (int i = 1; i <= n; i++)
		{
			n1[i] = n1[i-1]+i;
		}
		for (int i = 1; i <= n; i++)
		{
			if (n1[i+1]*c>m)
			{
				cout << min(n, i+1);
				return 0;
			}
		}
		cout << n;
		return 0;
	}
	sort(a+1, a+n+1);
	for (int i = 1; i <= n; i++)
	{
		s[i] = s[i-1] + a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if ((i-j)*a[i]-(s[i-1]-s[j-1]) <= m)
				ans = max(ans, i-j+1);
		}
	}
	cout << ans;
	return 0;
}
