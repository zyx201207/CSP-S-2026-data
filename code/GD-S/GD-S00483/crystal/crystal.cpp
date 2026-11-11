#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 10;
int n, m, idx = 1;
int a[N], c[N], maxn = 1, cha[N], qian[N];

signed main()
{
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort (a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		qian[i] = qian[i - 1] + a[i];
	}
	for (int l = 1; l < n; l++)
	{
		for (int r = l + maxn; r <= n; r++)
		{
			if ((a[r] * (r - l + 1)) - (qian[r] - qian[l - 1]) <= m)
			{
				maxn = max (maxn, r - l + 1);
			}
			else
			{
				break;
			}
		}
	}
	cout << maxn << '\n';
	
	return 0;
} 
