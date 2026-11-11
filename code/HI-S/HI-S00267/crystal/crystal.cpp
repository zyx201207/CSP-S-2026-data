#include <bits/stdc++.h>
using namespace std;
long long n,m,p,bl,ans,a[1000000],b[1000000];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		p += a[i];
	}
	p /= n;
	for (int i = 1;i <= n;i++)
	{
		if (a[i] <= p)
		{
			b[i] = a[i];
			bl++;
		}
	}
	for (int i = 1;i <= bl;i++)
	{
		if (m -= (p - b[i]) >= 0)
		{
			ans ++;
			m -= (p-b[i]);
		}
	}
	for (int i = 1;i <= bl;i++)
	{
		if (b[i] = p)
		{
			ans += 1;
		}
	}
	cout << ans;
	return 0;
}
