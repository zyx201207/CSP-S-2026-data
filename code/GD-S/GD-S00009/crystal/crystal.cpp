#include <bits/stdc++.h>
using namespace std;

long long n, m, delta, a[500001];
bool flag = true;

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	
	for (long long i = 1; i <= n; ++i)
	{
		cin >> a[i];
		
		if (i == 2)
		{
			delta = a[2] - a[1];
		}
		
		if (i > 2 && a[i] - a[i - 1] != delta)
		{
			flag = false;
		}
	}
	
	if (flag)
	{
		for (long long i = 1; i <= n; ++i)
		{
			if (delta * i * (i - 1) / 2 > m)
			{
				cout << i - 1;
				
				break;
			}
		}
	}
	
	else
	{
		long long ans = 0;
		
		sort(a + 1, a + n + 1);
		
		for (long long i = 1; i <= n; ++i)
		{
			long long t = m, cnt = 1;
			
			for (long long j = i - 1; j > 0; --j)
			{
				if (a[i] - a[j] <= t)
				{
					t -= a[i] - a[j];
					++cnt;
				}
				
				else
				{
					break;
				}
			}
			
			ans = max(ans, cnt);
		}
		
		cout << ans;
	}
	
	return 0;
}
