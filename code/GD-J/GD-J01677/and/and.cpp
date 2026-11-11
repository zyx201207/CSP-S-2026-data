#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, a[200007], num, mx = LONG_LONG_MIN;
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	scanf("%lld%lld", &n, &m);
	for (ll i = 1; i <= n; i ++)
	{
		scanf("%lld", &a[i]);
		if (m == n)
		{
			if (i == 1) m = a[i];
			else m &= a[i];
		}
	}
	if (m == n) 
	{
		printf("%lld", m);
		return 0;
	}
	sort(a + 1, a + n + 1);
	num = a[n];
	for(ll i = n - 1; i >= n - m + 1; i --)
	{
		num &= a[i];
	}
	printf("%lld", num);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
