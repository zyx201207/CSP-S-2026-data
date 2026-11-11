#include <bits/stdc++.h>

using namespace std;

long long arr[200005][35];
bool brr[200005];

int main(void)
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n = 0;
	int m = 0;
	cin >> n >> m;
	long long a[200005]{};
	int maxnp = 0;
	for (int i = 0; i < n; i++)
	{
		long long cmp = 0;
		cin >> cmp;
		a[i] = cmp;
		for (int j = 0; cmp != 0; cmp /= 2, j++)
		{
			arr[i][j] = cmp % 2;
			maxnp = max(maxnp, j);
		}
	}
	long long ans = 0;
	for (int i = maxnp; i >= 0; i--)
	{
		int cmp = 0;
		for (int j = 0; j < n; j++)
		{
			if (brr[j])
			{
				continue;
			}
			cmp += arr[j][i];
		}
		if (cmp >= m)
		{
			for (int j = 0; j < n; j++)
			{
				if (brr[j])
				{
					continue;
				}
				if (arr[j][i] == 0)
				{
					brr[j] = true;
				}
			}
		}
	}
	int cmp1 = 0;
	for (int i = 0; i < n; i++)
	{
		if (!brr[i] && cmp1 == 0)
		{
			ans = a[i];
			cmp1 = 1;
		}
		else if (!brr[i])
		{
			ans = (ans & a[i]);
		}
	}
	cout << ans;
	return 0;
}
