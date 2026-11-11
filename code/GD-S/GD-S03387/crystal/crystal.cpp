#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+10;
ll n,m,a[N],sum[N];
bool check(ll x){
	ll minn=5e17;
	for(int i=x;i<=n;i++){
		ll temp=sum[i-1]-sum[i-x];
		minn=min(minn,(x-1)*a[i]-temp);
		if(minn<=m) return 1;
	}
	return 0;
}
void solve(){
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	ll l=1,r=n,ans=0;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	cout << ans; 
	return ;
}
ll T=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
//	cin >> T;
	while(T--) solve();
	return 0; 
}

