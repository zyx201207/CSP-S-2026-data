#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 10;
int n, length, sum;
int a [maxn];
char c [maxn];
int x;
int zifu (int a [], int m)
{
	x = 1;
	while (m > 0)
	{
		if (m > a [x])
		{
			m -= a [x];
			x ++;
		}
		else
		{
			break;
		}
	}
	return x;
}
signed main ()
{
	ios::sync_with_stdio (false);
	cin.tie (0);
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++)
	{
		cin >> a [i] >> c [i];
		length += a [i];
	}
	if (length % 2)//ÆæÊý 
	{
		for (int i = 1; i <= length / 2; i ++)
		{
//			cout << zifu (a, i) << " " << zifu (a, length - i) << " ";
//			cout << c [zifu (a, i)] << " " << c [zifu (a, length - i)];
			if (c [zifu (a, i)] != c [zifu (a, length - i + 1)])
			{
				sum ++;
			}
		}
	}
	else//Å¼Êý 
	{
		for (int i = 1; i <= length / 2; i ++)
		{
//			cout << c [zifu (a, i)] << c [zifu (a, length - i)];
			if (c [zifu (a, i)] != c [zifu (a, length - i + 1)])
			{
				sum ++;
			}
		}
	}
	cout << sum;
	return 0;
}
