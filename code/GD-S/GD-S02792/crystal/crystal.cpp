#include <bits/stdc++.h>
using namespace std;

long long a[500005];
long long sum[500005];

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	for(long long i = 1; i <= n; i++) {cin >> a[i];}
	sort(a + 1, a + n + 1);
	for(long long i = 1; i <= n; i++) {sum[i] = sum[i - 1] + a[i];}
	long long ans = 0;
	for(long long i = 1; i <= n; i++)
	{
		long long l = 1, r = i - 1;
		while(l < r)
		{
			long long mid = (l + r) / 2;
			if((i - 1 - (mid - 1)) * a[i] - sum[i - 1] + sum[mid - 1] > m) l = mid + 1;
			else r = mid;
		}
		if(i == n && l == 1)
		{
			if((m - (i - 1 - (l - 1)) * a[i] - sum[i - 1] + sum[l - 1]) % n == 0) ans = max(ans, n);
			else ans = max(ans, n - 1);
		}
		else ans = max(ans, i - l + 1);
	}
	cout << ans << endl;
	return 0;
 } 
