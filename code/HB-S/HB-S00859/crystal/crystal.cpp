//crystal
#include <bits/stdc++.h>
#define ll long long 
#define ls (x<<1)
#define rs (ls+1)
#define mod (ll)(1e9+7)
#define pii pair<int,int>
using namespace std;
const int N=5e5+5;
ll n,m,ans;
ll a[N],sum[N];
ll fen(ll i)
{
	ll l=1,r=i,mid;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m)r=mid-1;
		else l=mid+1;
//		cout<<i<<' '<<mid<<' '<<a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<<endl;
	}
	return i-l+1;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(ll i=1;i<=n;i++)
	{
		ans=max(ans,fen(i));
	}
	cout<<ans;
	return 0;
}
