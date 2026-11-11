#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int N=5e5+10;
int a[N];
int n;
long long m;
long long dp[N];
long long sum[N];
int now;
long long l,r,mid,cnt;
int erfen(long long x)
{
	l=1,r=x;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(m>=a[x]*(x-mid+1)-sum[x]+sum[mid-1])
			r=mid-1,cnt=mid;
		else
			l=mid+1;
	}
	return cnt;
}
int ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
//		now=lower(sum+1,sum+1+i,sum[i]-a[i]*(i*1ll)+m);
		now=erfen(i);
		ans=max(ans,i-now+1);
	}
	cout<<ans;
	return 0;
} 
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
