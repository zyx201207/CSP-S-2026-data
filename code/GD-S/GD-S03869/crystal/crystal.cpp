#include<bits/stdc++.h>
using namespace std;
long long sum[500005];
long long a[500005];
long long ans=-1e18;
long long n,m;
long long h(long long i,long long x)
{
	long long l=1,r=i;
	while(l<=r)
	{
		long long mid=(l+r+1)/2;
		if(x*(i-mid+1)-(sum[i]-sum[mid-1])<=m)
		{
			r=mid-1;
		}
		else 
		{
			l=mid+1;
		}
	}
	return l;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(long long i=1;i<=n;i++)
	{
		ans=max(ans,i-h(i,a[i])+1);
	}
	cout<<ans;
	return 0;
} 
