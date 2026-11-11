#include <bits/stdc++.h>
using namespace std;
long long m,n;
const int X=5*1e5+1;
long long x[X],num[X];
int ws(long long p)
{
	int sum=1,l=m;
	for (long long i=p-1;i >= 1;i--)
	{
		long long f=x[p]-x[i];
		if (f <= l)
		{
			sum++;
			l-=x[i];
		}
		else
		{
			return sum;
		}
	}
	return sum;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (long long i = 1;i <= n;i++)
	{
		cin >> x[i];
	}
	sort(x+1,x+n+1);
	for (long long i = n;i >= 1;i--)
	{
		num[i]=ws(i);
	}
	sort(num+1,num+n+1);
	cout << num[n];
	return 0;
}
