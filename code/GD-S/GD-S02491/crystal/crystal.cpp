#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5000005],ans=0,sum=0,sum2;
bool check(long long x)
{
	sum=0;
	for(int i=1;i<=x;i++)
	sum+=a[i];
	sum2=x*a[x];
	if(sum2-sum<=m) return 1;
	for(int i=x+1;i<=n;i++)
	{
		sum=sum+a[i]-a[i-x];
		sum2=a[i]*x;
		if(sum2-sum<=m) return 1;
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	scanf(" %lld",&a[i]);
	sort(a+1,a+n+1);
	long long l=1,r=n,mid;
	while(l<=r)
	{
		mid=l+(r-l)/2;
		if(check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
