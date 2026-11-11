#include <bits/stdc++.h>
using namespace std;

long long n, m;
long long tp;
long long a[200010];
bool flag[200010];
long long ad(long long maxn, long long num)
{
	if(num >= m)
	{
		return maxn;
	}
	long long maxnn = -0x3f3f3f3f;
	for(long long i = 1; i <= n; i++)
	{
		if(flag[i] || !a[i] || !(maxn & a[i]) || !maxn)
		{
			continue;
		}
		flag[i] = 1;
		maxnn = max(maxnn, ad(maxn & a[i], num + 1));
		flag[i] = 0;
	}
	return maxnn;
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	if(m == 1)
	{
		tp = -0x3f3f3f3f;
	}
	for(long long i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(m == 1)
		{
			tp = max(tp, a[i]);
		}
		if(m == n && i == 1)
		{
			tp = a[i];
		}
		if(m == n && i != 1)
		{
			tp &= a[i];
		}
	}
	if(m == 1 || m == n)
	{
		cout << tp;
		return 0;
	}
	long long maxnn = -0x3f3f3f3f;
	for(long long i = 1; i <= n; i++)
	{
		if(a[i])
		{
			flag[i] = 1;
			maxnn = max(maxnn, ad(a[i], 1));
			flag[i] = 0;
		}
	}
	cout << maxnn;
	return 0;
}
