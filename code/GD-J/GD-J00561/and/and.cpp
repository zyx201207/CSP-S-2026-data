#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const ll N=1e6+10;
ll n,m;
ll a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,greater<ll>());
	if(m==1){
		ll x=-1;
		for(ll i=1;i<=n;i++){
			x=max(x,a[i]);
		}
		cout<<x;
	}
	if(m==2){
		if(n>1e5){
		cout<<a[m];
		return 0;
	}
		ll x=-1;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				if(i==j)continue;
				x=max(x,a[i]&a[j]);
			}
		}
		cout<<x;
	}
	else{
		cout<<a[m];
	}
	return 0;
}
