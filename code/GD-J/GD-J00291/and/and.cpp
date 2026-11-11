#include <bits/stdc++.h>
using namespace std;
long long c,a[200009];

bool cmp (long long x,long long y)
{
	return x>y;
}
int main()
{
	long long n,m;
	freopen ("and.in","r",stdin);
	freopen ("and.out","w",stdout);
	cin >>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin >>a[i];
	}
	sort (a+1,a+n+1,cmp);
	c=a[1];
	for (int i=1;i<=n-m;i++)
	{
		c=c&a[i];
	}
	cout <<c;
	return 0;
}
