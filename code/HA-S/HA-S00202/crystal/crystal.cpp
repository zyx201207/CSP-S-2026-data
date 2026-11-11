#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1000001];
long long b[1000001];
bool c(long long e)
{
	long long num=0;
	for(long long i=2;i<=n;i++)
	{
		if(i<=e)
		num+=(i-1)*(a[i]-a[i-1]);
		if(i>e)
		{
			num+=e*(a[i]-a[i-1]);
			num-=a[i]-a[i-e];
			if(num<=m)
			{
				
				return true;
			}
		}
		if(i==e)
		{
			if(num<=m)
			{
				return true;
			}
		}
	}
	return false;
}
int main()
{

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	b[0]=0;
	b[1]=0;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long l=1,r=n;
	long long mid;
	while(l<r)
	{
		mid=(l+r)/2;
		if(c(mid))
		{
			l=mid+1;
		}
		else
		r=mid;
	}
	if(c(l))
	{
		if(c(l+1))
		{
			cout<<l+1;
		}
		else
		cout<<l;
	}
	else
	cout<<l-1;
	return 0;
}
