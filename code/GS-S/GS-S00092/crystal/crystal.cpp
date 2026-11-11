#include <bits/stdc++.h>
using namespace std;
long long d[5005] , b[5005][5005] , ans;
int main()
{
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	long long n , m;
	cin >> n >> m;
	long long a[n];
	for (long long i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1 , a + n + 1);
	if (n <= 5000)
	{
		for (long long i = 1;i < n;i++)
			d[i] = a[i + 1] - a[i];
		for (long long i = 1;i < n;i++)
		{
			for (long long j = i;j < n;j++)
			{
				b[i][j] = b[i][j - 1] + d[j] * (j - i + 1);
				if (b[i][j] > m)
				{
					ans = max(ans , j - i + 1);
					break;
				}
			}
		}
		cout << ans;
	}
	else
	{
		long long dd = a[2] - a[1];
		if (m % dd == 0)
			cout << m / dd + 1;
		else
			cout << m / dd;
	} 
	return 0;
}
