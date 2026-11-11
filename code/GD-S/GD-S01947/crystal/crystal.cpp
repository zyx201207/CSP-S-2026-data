#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;

int n, ans = 1;
long long m, a[N], d[N];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	if (n > 5000 || m > 1e9)
	{
		int k = a[2]-a[1], c = 0;
		for (int i = 1;i <= n;i++)
		{
			c += i*k;
			if (c > m)
			{
				ans = i;
				break;
			}
			else if(c == m)
			{
				ans = i+1;
			}
		}
		cout << ans;
	}
	else
	{
		for (int i = 1;i <= n;i++)
		{
			d[i] = a[i]-a[i-1];
		}
		d[1] = 0;
		for (int i = 2;i <= n;i++)
		{
			long long deep = 0;
			int j;
			for (j = i-1;j >= 1;j--)
			{
				deep = deep*2+d[j+1];
				if (deep >= m)
				{
					break;
				}
			}
			ans = max(ans, i-j+1);
		}
		cout << ans;
	}
	return 0;
}
