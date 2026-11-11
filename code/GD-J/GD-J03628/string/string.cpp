#include <bits/stdc++.h>
using namespace std;
int n, a[200005];
long long q, mid, ans;
char c[200005];
bool flag;
bool qwert(long long l)
{
	if (flag)
	{
		return (l <= mid);
	}
	else
	{
		return (l < mid);
	}
}
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
    	cin >> a[i] >> c[i];
    	mid += a[i];
	}
	if (mid % 2 == 1)
	{
		flag = true;
	}
	mid /= 2;
	mid++;
	for (int i = 1; i <= n; i++)
	{
		q += a[i];
		if (q >= mid)
		{
			mid = i;
			break;
		}
	}
	long long l = 1, r = n;
	while (qwert(l) && r >= mid)
	{
		if (a[l] > a[r])
		{
			if (c[l] != c[r])
			{
				ans += a[r];
				a[l] -= a[r];
				r--;
			}
			else
			{
				a[l] -= a[r];
				r--;
			}
		}
		else if (a[l] < a[r])
		{
			if (c[l] != c[r])
			{
				ans += a[l];
				a[r] -= a[l];
				l++;
			}
			else
			{
				a[r] -= a[l];
				l++;
			}
		}
		else
		{
			if (c[l] != c[r])
			{
				ans += a[l];
				l++;
				r--;
			}
			else
			{
				l++;
				r--;
			}
		}
	}
	cout << ans;
    return 0;
}
