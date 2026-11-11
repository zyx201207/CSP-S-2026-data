#include<bits/stdc++.h>
using namespace std;
long long n,x;
long long a[500005];
long long l;
long long r;
long long jc(long long o)
{
	long long s = 0;
	for(int i = 1;i <= n;++i)
	{
		if(a[i]<=o)
		{
			s+=(o-a[i]);
			
		}
		else
		{
			break;
		}
	}
	return s;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> x;

	cin >> a[1];
	l = a[1];
	r = a[1];
	for(int i = 2;i <= n;++i)
	{
		cin >> a[i];
		l = min(l,a[i]);
		r = max(r,a[i]);
	}
	sort(a,a +n);
	long long as = l;
	while(l<=r)
	{
		long long m = l + (r - l)/2;
		long long p = jc(m);
		if(p<=x)
		{
			as = max(as,m);
			l = m + 1;
		}
		else
		{
			r=m-1;
		}
	}
	long long t = 0;
	for(long long i = 1;i <= n;++i)
	{
		if(a[i]<=as)
		{
			t++;
		}else
		{
			break;
		}
	}
	
	
	cout << t;
	return 0;
}
