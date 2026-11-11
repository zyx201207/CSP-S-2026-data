#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e6+5;
ll n,m,ans;
ll a[N],d[N],f[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	if (n==1)
	{
		cout<<1;
		return 0;
	}
	for (ll i=1;i<=n;i++)
	scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for (ll i=2;i<=n;i++)
	{
		d[i]=a[i]-a[i-1];
		if (d[i]>=m) continue;
		ll cnt=0,j=1;
		while(cnt<=m&&j<i)
		{
			cnt+=a[i]-a[i-j];
			j++;
		} 
		ans=max(ans,j-1);
	}
	cout<<ans;
	/*f[1]=d[1]=0;
	for (ll i=2;i<=n;i++)
	{
		d[i]=a[i]-a[i-1];
		f[i]=(i-1)*d[i]+f[i-1];
	}
	for (int i=1;i<=n;i++)
	{
		if (f[i]>m)
		{
			 ans=i;
			 break;
		}
	}
	cout<<ans-1;*/
	return 0;
}
