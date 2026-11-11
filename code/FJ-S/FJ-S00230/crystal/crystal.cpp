#include<bits/stdc++.h>

using namespace std;

long long n,m,a[5000100],b[500010],maxx=-9e18;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	for(long long i=1;i<=n;i++)
	{
		long long l=i,r=n;
		while(l<r)
		{
			long long mid=(l+r+1)/2;
			long long x=b[mid]-b[i-1];
			long long y=(mid-i+1)*a[mid]-x;
			if(y<=m)l=mid;
			else r=mid-1; 
		}
		long long x=b[r]-b[i-1];
		long long y=(r-i+1)*a[r]-x;
		if(y<=m) maxx=max(maxx,r-i+1);
	}
	cout<<maxx;
	return 0;
}
