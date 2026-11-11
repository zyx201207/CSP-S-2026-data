#include <bits/stdc++.h>
using namespace std;

int n, m, a[200005];

bool f[200005];

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= n; i ++)
	{
		f[i] = true;
	}
	int cnt = n, sum = 0;
	for(int i = 29; i >= 0; i --)
	{
		int cur = 0;
		for(int j = 1; j <= n; j ++)
		{
			if(f[j] == true && (1 << i & a[j]) == 0)
			{
				cur ++;
			}
		}
		if(cnt - cur < m)
		{
			continue;
		}
		sum += (1 << i);
		for(int j = 1; j <= n; j ++)
		{
			if(f[j] == true && (1 << i & a[j]) == 0)
			{
				f[j] = false;
				cnt --;
			}
		}
	}
	cout << sum << '\n';
	return 0;
}
