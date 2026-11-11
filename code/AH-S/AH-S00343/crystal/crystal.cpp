#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500010],c[500010];
int check(long long s)
{
	int i;
	long long x,y;
	for(i=1;i<=n-s+1;i++)
	{
		x=c[i+s-1]-c[i-1];
		y=a[i+s-1]*s;
		x=y-x;
		if(x<=m)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int i;
	long long l,r,mid;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	c[1]=a[1];
	c[0]=0;
	for(i=2;i<=n;i++)
	{
		c[i]=a[i]+c[i-1];
	}
	l=1;r=n;
	while(l<r-1)
	{
		mid=(l+r)/2;
		if(check(mid)==1)
		{
			l=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	if(check(r)==1)
	{
		cout<<r;
	}
	else if(check(mid)==1)
	{
		cout<<mid;
	}
	
	else if(check(l)==1)
	{
		cout<<l;
	}
	return 0;
}
