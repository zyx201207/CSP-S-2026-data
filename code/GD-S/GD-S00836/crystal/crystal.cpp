#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+100;
ll n,m;
ll a[N];
ll ans=-2e18;
bool ok=true,ook=true;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		if(a[i]!=i){
			ok=false;
			break;
		}
	}
	ll cha=a[2]-a[1];
	for(ll i=3;i<=n;i++){
		if(a[i]-a[i-1]!=cha){
			ook=false;
		}
	}
	if(ok){
		if(m<n){
			cout<<m+1;
		}else{
			cout<<n;
		}
	}else if(ook){
		ll q=m/cha+1;
		if(q<n){
			cout<<q;
		}else{
			cout<<n;
		}
	}else{
		sort(a+1,a+1+n);
		ll best;
		for(ll i=1;i<=n;i++){
			ll cnt=0;
			for(ll j=1;j<i;j++){
				cnt+=(a[i]-a[j]);
			}
			if(cnt<=m){
				if(cnt>=ans){
					ans=cnt;
					best=i;
				}
			}
		}
		cout<<best;
	}
	return 0;
}
