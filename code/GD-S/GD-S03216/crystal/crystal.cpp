#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],b[1000005],c[1000005],d,e,f,g,h,l,r,ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	l=1;
	r=n;
	for(int i=1;i<=n;i++)
	b[i]=b[i-1]+a[i];	long long minn=1e18;
	
	while(l<=r)
	{
		minn=1e18;
		long long mid=(l+r)/2;
		for(long long i=1;i<=n;i++)
		{
			if(i>=mid)
			{
				minn=min(mid*a[i]-b[i]+b[i-mid],minn);
			}
		}
		if(minn<=m)
		{
			l=mid+1;
			ans=mid;
		}
		else
		r=mid-1;
	}
	cout<<ans;
	return 0;}
