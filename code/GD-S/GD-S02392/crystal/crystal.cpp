#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;

int a[500010];

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int ans = 0;
	int l = 1, r = 2;
	int sum = a[2] - a[1];
	while (r <= n)
	{
		if (sum > m)
		{
			if (r - l > 1)
			{
				sum -= a[r] - a[l];
				l++;
			}
			else
			{
				sum -= a[r] - a[l];
				r++;
				l++;
				sum += a[r] - a[l]; 
			}
		}
		else
		{
			ans = max (ans, r - l + 1);
			int x = r - l;
			r++;
			int y = a[r] - a[r - 1];
			sum += x * y; 
		}
	
	}
	cout << ans; 
	return 0;	
} 
