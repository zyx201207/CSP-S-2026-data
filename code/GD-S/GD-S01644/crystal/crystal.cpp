#include<bits/stdc++.h>
#define ll long long
#define no ios::sync_with_stdio(0);
#define TLE cin.tie(0),cout.tie(0);
using namespace std;
const ll N=5e5+5;
ll n,m,a[N],ans=0;
void solve(){
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1,l=1,r=0,res=1;i<=n;i++,l=1,r=i-1,res=i)
	{
		while(l<=r)
		{
			ll mid=(l+r)>>1;
			if(a[i]*(i-mid)-(a[i-1]-a[mid-1])<=m)r=mid-1,res=mid;
			else l=mid+1;
		}
		ans=max(ans,i-res+1),a[i]+=a[i-1];
	}
	cout<<ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	no TLE
	ll _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}
