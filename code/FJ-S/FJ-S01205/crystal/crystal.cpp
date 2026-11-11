#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5;

int a[N + 5], d[N + 5];
 
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	bool is_special = 1;
	for (int i = 2; i <= n; i++)
	{
		d[i] = a[i] - a[i - 1];
		if (i >= 3 && d[i] != d[i - 1]) is_special = 0;
	}
	
	if (is_special)
	{
		int ans = 0, add = 0, base = 1, dis = d[2];
		while (add <= m)
		{
			add += dis * base;
			base ++;
			ans ++;
		}
		cout << ans;
		return 0;
	}
	
	int maxn = 1;
	for (int i = 2; i <= n; i++)
	{
		int add = 0, sum = 0;
		bool f = 1;
		for (int j = i; j >= 2; j--)
		{
			sum += d[j];
			add += sum;
			if (add > m) 
			{
				maxn = max(maxn, i - j);
				f = 0;
				break;
			}
		}
		if (f) maxn = max(maxn, i);
	}
	cout << maxn;
	return 0;
}
