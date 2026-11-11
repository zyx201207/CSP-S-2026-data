#include <bits/stdc++.h>
using namespace std;

int n, a[200005];
char c[200005];

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	long long sum = 0;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i] >> c[i];
		sum += a[i];
	}
	int lid = 1, rid = n;
	long long l = a[1], r = sum - a[n] + 1, k = 0;
	long long ans = 0;
	for(; lid <= rid; )
	{
		if(c[lid] != c[rid])
		{
			ans += min(l, sum - r + 1) - k;
		}
		k = min(l, sum - r + 1);
		if(k == l)
		{
			lid ++;
			l += a[lid];
		}
		if(k == sum - r + 1)
		{
			rid --;
			r -= a[rid];
		}
	}
	cout << ans << '\n';
	return 0;
}
