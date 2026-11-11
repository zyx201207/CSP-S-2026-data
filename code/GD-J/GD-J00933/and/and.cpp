#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
ll a[200100];
ll ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		ll mx=0;
		for(ll i=1;i<=n;i++)mx=max(mx,a[i]);
		cout<<mx;
		return 0;
	}
	sort(a+1,a+n+1,greater<ll>());
	if(m==n){
		ll res=a[1];
		for(ll i=1;i<=n;i++)res&=a[i];
		cout<<res;
		return 0;
	}
	ans=a[1];
	for(ll i=1;i<=m;i++){
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}
