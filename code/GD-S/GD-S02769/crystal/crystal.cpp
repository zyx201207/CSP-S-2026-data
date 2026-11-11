#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
#define ll long long
ll cnt,ans,a[500005];
bool ch (ll k,ll m){
	cnt=0;
	for (ll i=k;i>=1;i--){
		if (m<=0){
			break;
		}
		if (m>=a[k]-a[i]){
			m-=(a[k]-a[i]);
			cnt++;
		}
	}
	if (cnt<ans){
		return false;
	}
	return true;
}
ll n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (ll i=1;i<=n;i++){
		cin>>a[i];
	}
	ll l=1,r=n;
	sort (a+1,a+n+1);
	while (l<=r){
		ll mid=(l+r)/2;
		if (ch(mid,m)){
			ans=cnt;
			l=mid+1;
		} 
		else {
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
} 
