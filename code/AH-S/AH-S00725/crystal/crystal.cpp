#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],dp[500005],maxt=1;
long long v(long long l,long long r,long long u)
{
	if(l==r)return u-l;
	long long mid=(l+r)/2;
	if(dp[u]-dp[mid]-(a[u]-a[mid])*(mid+1)>m)
		return v(mid+1,r,u);
	else
		return v(l,mid,u);
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	dp[0]=0;
	for(long long i=1;i<n;i++)
		dp[i]=dp[i-1]+(a[i]-a[i-1])*i;
	for(long long i=1;i<n;i++)
		maxt=max(maxt,v(0,i,i));
	cout<<maxt;
	return 0;
}
