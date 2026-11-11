#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long sum[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	sum[i]=sum[i-1]+a[i];
	long long out=0;
	for(int i=1;i<=n;i++)
	{
		long long l=1,r=i,ans=0;
		while(l<=r)
		{
			long long mid=(l+r)/2;
			if(a[i]*(i-mid)-(sum[i-1]-sum[mid-1])<=m)
			ans=i-mid+1,r=mid-1;
			else
			l=mid+1;
		}
		out=max(out,ans);
	}
	cout<<out;
}
