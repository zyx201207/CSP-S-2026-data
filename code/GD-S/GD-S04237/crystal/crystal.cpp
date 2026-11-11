#include <bits/stdc++.h>
using namespace std;
const long long N = 5 * 1e5 + 5;
long long n, m, cnt, k, a[N], minx = N;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	for(int i = 0; i < n; i++) if(i > 0) minx = min(minx, a[i] - a[i - 1]);
	for(int i = 0; i < n; i++)
	{
		if(i > 0 && a[i] - a[i - 1] == minx)
		{
			k = a[i];
		}
	}
	while(m <= 0)
	{
		for(int i = k; i > 0; i--)
		{
			if(m <= 0) break;
			else
			{
				for(; a[i] <= k ; a[i]++)
				{
					m--;
					if(m <= 0) break;
				}
			}
		}
		for(int i = n; i > 0; i--)
		{
			if(a[i] == k)
			{
				k = a[i + 1];
			}
			continue;
		}
	}
	for(int i = 0; i < n; i++)
	{
		if(a[i] == k) cnt++;
	}
	cout << cnt + 2;
	return 0;
}
