#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+5;
ll a[N],sum[N],n,m;
bool chk(ll x)
{
	for (ll i=x;i<=n;i++)
	{
		if ((a[i]*x-(sum[i]-sum[i-x]))<=m) return 1;
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >>n>>m;
	for (ll i=1;i<=n;i++) cin >>a[i];
	sort(a+1,a+n+1);
	for (ll i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	ll l=1,r=n,ans=0;
	while (l<=r)
	{
		ll mid=(l+r)>>1;
		if (chk(mid)){l=mid+1,ans=mid;}
		else r=mid-1;
	}
	cout <<ans;
	return 0;
 } 
 /*100·Ö¶þµÈ½± 14:51 
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7


¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿

ÄÇ¾ÍºÃºÃµÀ¸ö±ð°É 
 
 */
