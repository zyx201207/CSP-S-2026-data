//贵阳市第十九中学 刘承福 GZ-S00032
#include <bits/stdc++.h>
using namespace std;

long long n;
long long m;
long long a[500005], b[500005];
bool flag = true, flag2 = true;

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] != i) flag = false;
	}
	if (flag)
	{
		int cnt = 1;
		for (long long i = 1; i <= m; i++)
		{
			if (m >= i)
			{
				m -= i;
				cnt++;
			}
		}
		cout << cnt << endl;
		return 0;
	}
	long long gc = a[2] - a[1];
	for (int i = 2; i <= n; i++)
	{
		if (a[i] - a[i-1] != gc) flag2 = false;
	}
	if (flag2)
	{
		int cnt = 1;
		for (long long i = gc; i <= m; i+=gc)
		{
			if (m >= i)
			{
				m -= i;
				cnt++;
			}
		}
		cout << cnt << endl;
		return 0;
	}
	else
	{
		long long ans = 0;
		sort(a+1, a+n+1);
		for (int i = 1; i <= n; i++)
		{
			long long cnt = 0, sum = 0;
			for (int j = 1; j <= n; j++)
			{
				if (i != j)	b[++cnt] = a[i] - a[j];
			}
			sort(b+1, b+n+1);
			for (int j = 1; j <= cnt; j++)
			{
				if (m >= b[i])
				{
					m -= b[i];
					sum++;
				}
			}
			ans = max(ans, sum);
		}
		cout << ans << endl;
	}
	return 0;
}
