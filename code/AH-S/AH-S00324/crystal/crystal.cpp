#include<bits/stdc++.h>
using namespace std;
long long n,m,l=1,r,mid,maxn=INT_MIN;
long long a[500005],sum[500005];
bool check(long long mid)
{
	for(int i=1,j=mid;j<=n;i++,j++)
	{
		long long ans=(j-1)*a[j]-(sum[j-1]-sum[i-1]);
		//cout<<mid<<' '<<i<<' '<<j<<' '<<ans<<'\n'; 
		if(ans<=m) return 1;
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	r=n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	//cout<<(l+r)/2;
	while(l<r)
	{
		mid=(l+r)/2;
		if(check(mid)) 
		{
			l=mid+1;
			maxn=max(maxn,mid);
		}
		else r=mid-1;
	}
	cout<<maxn;
	return 0;
}
