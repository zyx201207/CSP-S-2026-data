#include <bits/stdc++.h>
using namespace std;
char c[200005];
int n, l, r;
long long m, s, ss, a[200005];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
		s += a[i];
	}
	ss = (s + 1) / 2;
	for (int i = 1; i <= n; i++)
	{
		ss -= a[i];
		if (ss == 0)
		{
			if (s / 2 == 1)
			{
				a[i]--;
			}
			l = i;
			r = i + 1;
			break;
		}
		else if (ss < 0)
		{
			if (s % 2 == 1)
			{
				if (a[i] + ss - 1 > -ss)
				{
					a[i] += ss - 1;
					l = i;
					r = i + 1;
				}
				else if (a[i] + ss - 1 < -ss)
				{
					a[i] = -ss;
					l = i - 1;
					r = i;
				}
				else
				{
					l = i - 1;
					r = i + 1;
				}
			}
			else
			{
				if (a[i] + ss > -ss)
				{
					a[i] += ss;
					l = i;
					r = i + 1;
				}
				else if (a[i] + ss < -ss)
				{
					a[i] = -ss;
					l = i - 1;
					r = i;
				}
				else
				{
					l = i - 1;
					r = i + 1;
				}
			}
			break;
		}
	}
	while ((l > 0) && (r <= n))
	{
		if (c[l] == c[r])
		{
			if (a[l] < a[r])
			{
				a[r] -= a[l];
				l--;
			}
			else if (a[l] > a[r])
			{
				a[l] -= a[r];
				r++;
			}
			else
			{
				l--;
				r++;
			}
		}
		else
		{
			if (a[l] < a[r])
			{
				m += a[l];
				a[r] -= a[l];
				l--;
			}
			else if (a[l] > a[r])
			{
				m += a[r];
				a[l] -= a[r];
				r++;
			}
			else
			{
				m += a[l];
				l--;
				r++;
			}
		}
	}
	cout << m;
	return 0;
}
