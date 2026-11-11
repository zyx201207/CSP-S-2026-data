#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m,a[N],sum,ans;
bool check(ll x)
{
	ll tot=0,cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=x&&x-a[i]<=m){cnt++;tot+=x-a[i];}
		if(tot>m) return false;
	}
	ans=max(ans,cnt);
	return true;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),sum+=a[i];
	sort(a+1,a+1+n);
	ll l=a[1],r=a[n]+m;
	while(l<=r)
	{
		ll mid=l+(r-l)/2;
		if(check(mid))
		{
			l=mid+1;
		}
		else r=mid-1;
	}
	printf("%lld",ans);
	return 0;
} 
