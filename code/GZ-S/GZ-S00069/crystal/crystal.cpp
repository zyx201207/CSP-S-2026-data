//GZ-S00069贵州省兴义市第八中学 刘宸浩
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll n,m;
ll a[N],sum[N];
ll solve1()
{
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	} 
	sort(a+1,a+n+1);
	ll ans=0;
	for(ll len=2;len<=n;len++)
	{
		//cerr<<ans<<" ";
		for(ll l=1;l+len-1<=n;l++)
		{
			ll r=l+len-1;
			ll L=a[l]+m;
			ll R=a[r];
			if(L>R) continue;
			while(L<=R)
			{
				ll mid=(L+R)/2;
				cerr<<len<<" "<<mid;
				ll cnt=(len*mid)-(sum[r]-sum[l-1]);
				cerr<<cnt<<" ";
				if(cnt==m)
				{
					ans=len;
					break;
				} 
				else if(cnt>m)
				{
					R=mid-1;
				}else if(cnt<m)
				{
					L=mid;
				}
			}
		}	
	}
	return ans; 
}
int main()
{
	ios::sync_with_stdio(false);//cin.tie(nullptr);
	freopen("srystal.in","r",stdin);
	freopen("srystal.out","w",stdout);
	cout<<solve1()-1;
	return 0;
} 
