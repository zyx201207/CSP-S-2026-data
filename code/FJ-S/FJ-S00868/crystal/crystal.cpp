#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
long long n, m, a[500005] = {};

bool check(long long x)
{
	long long sum = 0, av = a[x];
	for(int i = 1; i <= x; i++) sum += av-a[i];
	return sum <= m;
}
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	long long l = 0, r = n, ans = 0;
	while(l <= r)
	{
		long long mid = (l+r)/2;
		if(check(mid))
		{
			ans = mid;
			l = mid+1;
		}
		else r = mid-1;
	}
	cout << ans;
	return 0;
}
