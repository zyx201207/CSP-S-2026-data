#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAXN=5e5+5;
ll n,m,a[MAXN],ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	ll sum=0,L=1;
	for(ll i=1;i<=n;i++)
	{
		sum+=(a[i]-a[i-1])*(i-L);
		while(sum>m) sum-=a[i]-a[L],L++;
		ans=max(ans,i-L+1);
	}
	printf("%lld",ans);
	return 0;
}
