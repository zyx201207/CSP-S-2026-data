#include<bits/stdc++.h>
using namespace std;
long long a[500005],sum[500005];
long long l,r;
long long ma=0,s=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.in","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long f=1;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=i)
		{
			f=0;
		}
	}
	if(f==1)
	{
		long long s=0,i;
		for(i=1;s<=m;i++)
		{
			s=s+i;
		}
		if(i>n)
		{
			i=n;
		}
		cout<<i-1;
		return 0;
	}
	sort(a+1,a+n+1);
	l=1;
	r=1;
	while(l<=r&&r<=n)
	{
		long long t=r-l+1;
		long long t1=a[r+1]-a[r];
		ma=max(ma,t);
		if(m>=s+t*t1)
		{
			s=s+t*t1;
			r++;
		}
		else
		{
			s-=a[r],s+=a[l];
			l++;
		}
	}
	cout<<ma;
	return 0;
}
