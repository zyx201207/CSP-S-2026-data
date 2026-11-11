#include <bits/stdc++.h>
using namespace std;

long long n, m, a[1000005], sum[1000005], ans;

bool _1(long long x, long long y)
{
	return (((x - y + 1) * a[x] - (sum[x] - sum[y - 1])) <= m);
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
	{
		sum[i] = sum[i - 1] + a[i];
	}
	for(int i = 1; i <= n; i++)
	{
		long long l = 1, r = i;
		while(l < r)
		{
			long long mid = (l + r - 1) >> 1;
			if(_1(i, mid))
			{
				r = mid;
			}
			else
			{
				l = mid + 1;
			}
		}
		ans = max(ans, i - l + 1);
	}
	cout << ans;
	return 0;
}
