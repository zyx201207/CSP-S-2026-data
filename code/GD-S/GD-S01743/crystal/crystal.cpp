#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e5 + 5;
int ans = 0,n,m,mid,l = INT_MAX,r = 1e12,a[maxn];
int check(int c)
{
	int sum = 0;
	for (int i = 1;i <= n;i++)
	{
		sum += max(0ll,c - a[i]);
	}
	return sum;
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	bool f = true;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if (a[i] != a[1])
		{
			f = false;
		}
		l = min(l,a[i]);
	}
	if (f)
	{
		cout << n;
		return 0;
	}
	while (l <= r)
	{
		mid = l + (r - l) / 2;
		if (check(mid) <= m)
		{
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	for (int i = 1;i <= n;i++)
	{
		if (a[i] <= r)
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
/*
5 5
1 2 4 8 9
*/
