#include<bits/stdc++.h>
using namespace std;

long long a[500005];
long long s[500005];


int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;s[0]=0;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}

	sort(&a[1],&a[n+1]);
	
	for(long long i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	long long y=0;
	for(long long x=1;x<=n;x++)
	{
		long long l=x,r=n;
		while(l<r)
		{
			long long k=(l+r)/2+1;
			long long t=(k-x+1)*a[k]-s[k]+s[x-1];
			if(t<=m)l=k;
			else r=k-1;		
		}
		y=max(y,l-x+1);
	}
	cout<<y;
	return 0;
} 


