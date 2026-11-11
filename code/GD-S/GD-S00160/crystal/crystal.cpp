#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[500005],s[500005],ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		ll l=0,r=i,mid;
		while(l+1<r)
		{
			mid=(l+r)/2;
			if((i-mid)*a[i]-(s[i-1]-s[mid-1])>m)l=mid;
			else r=mid;
		}
		ans=max(ans,i-l);
	}
	printf("%lld",ans);
	return 0;
}
