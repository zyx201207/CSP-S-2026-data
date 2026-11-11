#include <bits/stdc++.h>
using namespace std;

long long n, cnt = 0, sum = 0, l, r, i, j;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	long long a[n];
	char c[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> c[i];
	}
	l = 0;
	r = n - 1;
	i = 0;
	j = a[n] - 1;
	while(true)
	{
		if (c[l] != c[r])
		{
			cnt++;
		}
		i++;
		j--;
		if (i > a[l] - 1)
		{
			l++;
			i = 0;
		}
		if (j < 0)
		{
			r--;
			j = a[r] - 1;
		}
		if (l > r)
		{
			break;
		}
		if (l == r && i >= j)
		{
			break;
		}
	}
	cout << cnt;
	return 0;
}
