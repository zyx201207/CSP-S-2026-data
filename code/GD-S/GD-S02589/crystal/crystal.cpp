#include <bits/stdc++.h>
#define ll long long
using namespace std;
const double eps = 1e-12;
const int N = 5e5 + 20; 
int n;
ll m;
ll a[N];
int mx;
ll b;
//暴力，预计得分80 
int main ()
{
	ios::sync_with_stdio (false);
	cin.tie (0);
//	cout.tie (0);
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	ll ans = 0;
	sort (a + 1, a + n + 1);
	b = a[2] - a[1];
	bool d = 1;
	for (int i = 3; i <= n; ++i)
	{
		if (a[i] - a[i - 1] != b)
		{
			d = 0;
			break;
		}
	}
	if (d == 1)
	{
		m /= b;
		mx = ((int)sqrt (8 * m + 1) + 1) / 2;
		cout << min (mx, n);
		return 0;
	}else{
		for (int i = 1; i <= n; ++i)
		{
			ans = 0;
			int j;
			for (j = i - 1; j >= 1; --j)
			{	
				if (ans + a[i] - a[j] > m)
				{
					break;				
				}
				ans += a[i] - a[j];
			}
			mx = max (mx, i - j);
		}	
	}
	cout << mx;
	return 0;
}
