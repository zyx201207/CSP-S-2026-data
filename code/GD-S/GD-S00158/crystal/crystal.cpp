#include<bits/stdc++.h>
using namespace std;
long long n,m,a[532235],sum,ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(long long l=1,r=1;r<=n;r++)
	{
		sum+=a[r];
		while(a[r]*(r-l+1)>sum+m) l++,sum-=a[l];
		ans=max(ans,r-l+1);
	}
	printf("%lld",ans);
	return 0;
}
