#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, d, s, a[500005];
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int l = 1;
	for (int i = 1; i <= n; i++)
	{
		while (d > m)
		{
			d -= a[i] - a[l];
			l++;
		}
		s = max(s, i - l + 1);
		d += (i - l + 1) * (a[i + 1] - a[i]);
	}
	cout << s;
	return 0; 
} 
