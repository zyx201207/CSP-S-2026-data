#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long c[200005];
long long ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		char x;
		cin>>a[i]>>x;
		c[i]=x-'a';
	}
	for(long long i=1;i<=n/2;i++)
	{
		long long x=a[i];
		long long y=a[n-i+1];
		if(x==y) if(c[i]!=c[n-i+1]) ans+=x;
		if(x>y)
		{
			long long k=x-y;
			if(c[i]!=c[n-i+1])
			{
				ans+=y;
			}
			if(c[i]==c[i+1])
			{
				a[i+1]+=k;
			}
			else if(c[i]==c[n-i])
			{
				a[n-i]-=k;
			}
			else 
			{
				ans+=k;
				if(a[n-i]>a[i+1])
				a[n-i]-=k;
				else 
				a[n-i]+=k;
			}
		}
		if(y>x)
		{
			long long k=y-x;
			if(c[i]!=c[n-i+1])
			{
				ans+=x;
			}
			if(c[n-i+1]==c[n-i])
			{
				a[n-i]+=k;
			}
			else if(c[n-i+1]==c[i+1])
			{
				a[i+1]-=k;
			}
			else 
			{
				ans+=k;
				if(a[n-i]>a[i+1])
				a[n-i]-=k;
				else 
				a[n-i]+=k;
			}
		}
	}
	cout<<ans;
	return 0;	
} 
