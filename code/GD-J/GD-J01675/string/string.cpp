#include <bits/stdc++.h>
using namespace std;
int n,a[100005];
char c[100005];
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i] >> c[i];
	}
	for (int i = 1;i <= n / 2;i++)
	{
		if (c[i] != c[n - i + 1])
		{
			if (a[i] == a[n - i + 1])
			{
				ans += a[i];
			}
			else if (a[i] <= a[n - i + 1])
			{
				if (c[i + 1] != c[n - i + 1])
				{
					ans += a[n - i + 1];
				}
				else
				{
					ans += a[i];
					
				}
				a[i + 1] -= a[n - i + 1] - a[i];
			}
			else 
			{
				if (c[i] != c[n - i])
				{
					ans += a[i];
				}
				else
				{
					ans += a[n - i + 1];
					
				}
				a[n - i] -= a[i] - a[n - i + 1];
			}
		}
		else
		{
			if (a[i] == a[n - i + 1])
			{
				continue;
			}
			else if (a[i] <= a[n - i + 1])
			{
				if (c[i + 1] != c[n - i + 1])
				{
					ans += a[n - i + 1] - a[i];
				}
				a[i + 1] -= a[n - i + 1] - a[i];
			}
			else 
			{
				if (c[i] != c[n - i])
				{
					ans += a[i] - a[n - i + 1];
				}
				a[n - i] -= a[i] - a[n - i + 1];
			}
		}
	}
	cout << ans;
	return 0;
}
