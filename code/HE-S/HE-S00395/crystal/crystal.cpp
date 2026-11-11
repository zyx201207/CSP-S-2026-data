#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, a[500005], l, r, mid, sum[500005];
bool check(ll x)
{
	ll ans =  LLONG_MAX;
	for(int l = 1, r = x; r <= n; ++l, ++r)
	{
		ans = min(ans, a[r] * x - sum[r] + sum[l - 1]);
	}
	if(ans < 0) return 0; 
	return ans <= m;
}
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i)
	{
		sum[i] = sum[i - 1] + a[i];
	}
	l = 1, r = n;
	while(l < r)
	{
		mid = l + r + 1 >> 1;
		if(check(mid))
		{
			l = mid;
		}
		else
		{
			r = mid - 1;
		}
	}
	cout << l;
	return 0;
}
