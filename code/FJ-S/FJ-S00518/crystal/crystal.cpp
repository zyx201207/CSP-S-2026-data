#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m,a[N],s[N],ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;++i)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	ll l=1;
	for(ll i=1;i<=n;++i)
	{
		s[i]=s[i-1]+a[i];
		while(l<=i&&a[i]*(i-l+1)-(s[i]-s[l-1])>m)
			++l;
		ans=max(ans,i-l+1);
	}
	printf("%lld",ans);
	return 0;
}
