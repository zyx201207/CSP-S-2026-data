#include <bits/stdc++.h>
using namespace std;
long long n,a[200050],sum,m,ans,x,y;
char c[200050],num;
int bj (int l,int r)
{
	if (l > r) return 1;
	if (r > l) return 2;
	if (l == r) return 1;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i] >> c[i];
	}
	x = 1;
	y = n;
	while (1)
	{
		if (x > y)
		{
			break;
		}
		while (1)
		{
			if (x > y)
			{
				cout << ans;
				return 0;
			}
			if (sum <= 0) break;
			if (m == 1)
			{
				if (sum <= a[y])
				{
					ans += sum;
					a[y] -= sum;
					sum = 0;
				}
				else
				{
					ans += a[y];
					sum -= a[y];
					y--;
				}
			}
			if (m == 2)
			{
				if (sum <= a[x])
				{
					ans += sum;
					a[x] -= sum;
					sum = 0;
				}
				else
				{
					ans += a[x];
					sum -= a[x];
					x++;
				}
			}
		}
		if (c[x] == c[y])
		{
			sum = abs(a[x] - a[y]);
			m = bj(a[x],a[y]);
			if (m == 1) num = c[x];
			if (m == 2) num = c[y];
			x++;
			y--;
		}
		else
		{
			sum = abs(a[x] - a[y]);
			m = bj(a[x],a[y]);
			if (m == 1) num = c[x];
			if (m == 2) num = c[y];
			int t = max(a[x],a[y]) - sum;
			ans += t;
			x++;
			y--;
		}
	}
	cout << ans;
	return 0;
}
