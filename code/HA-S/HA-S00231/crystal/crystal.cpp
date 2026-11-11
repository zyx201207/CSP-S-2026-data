#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m;
ll a[500010];
ll s[500010];
ll ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(ll i=1;i<=n;++i){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;++i){
		s[i]=s[i-1]+a[i];
	}
	ans=1;
	for(ll i=2;i<=n;++i){
		ll l=1,r=i-1;
		if(a[i]*(i-1)-s[i-1]<=m){
			ans=max(ans,i);
			continue;
		}
		if(a[i]-a[i-1]>m){
			ans=max(ans,1ll);
			continue;
		}
		while(l<r){
			ll mid=l+(r-l)/2;
			if(a[i]*(i-mid)-(s[i-1]-s[mid-1])<=m){
				r=mid;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-l+1);
	}
	cout << ans;
	return 0;
}
// final ver.
