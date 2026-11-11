#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500010],s[500010],ans=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	for(int i=2;i<=n;i++)
	{
		ll l=1,r=i-1;
		while(l<r)
		{
			ll mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m) 
			{
				ans=max(ans,i-mid+1);
				r=mid;
			}
			else l=mid+1;
		}
		
	}
	printf("%lld",ans);
	return 0;
}
