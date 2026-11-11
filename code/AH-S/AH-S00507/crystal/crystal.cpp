#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],sum[500005],ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(ll i=1;i<=n;i++)
	{
		ll l=1,r=n;
		while(l<r)
		{
			ll mid=l+r>>1;
			if(i<mid)
			{
				r=mid;
				continue;
			}
			ll k=a[i]*mid-(sum[i]-sum[i-mid]);
			if(k>=0&&k<=m)l=mid+1;
			else r=mid;
		}
		ans=max(ans,l-1);
		//cout<<ans<<endl;
	}
	cout<<ans;
	return 0;
}
