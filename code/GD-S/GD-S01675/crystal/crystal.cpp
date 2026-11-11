#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
long long n , m , ans;
long long c[N] , f[N];

int main()
{
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (long long i = 1 ; i <= n ; i ++)
	{
		cin >> c[i];
	}
	sort(c , c + n + 1);
	for (long long i = 1 ; i <= n ; i ++)
	{
		f[i] = f[i - 1] + c[i];
		if (c[i] * i - f[i] <= m)
		{
			ans = max(ans , i);
		}
		else
		{
			break;
		}
	}
	if (n < 31622)
	{
		for (long long i = 1 ; i <= n ; i ++)
		{
			f[i] = f[i - 1] + c[i];
			for (long long j = 1 ; j <= i ; j ++)
			{
				if (c[i] * (i - j + 1) - (f[i] - f[j - 1]) <= m)
				{
					ans = max(ans , i - j + 1);
				}
			}
		}
	}
	cout << ans << '\n';
	
	return 0;
}
