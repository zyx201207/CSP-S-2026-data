#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,m,a[500005],sum[500005];
bool check(ll x){
	for(int i=1;i+x-1<=n;i++){
		if(sum[i+x-1]-sum[i-1]+m>=a[i+x-1]*x){
			return 1;
		}
	}
	return 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >>n>>m;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}  
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	ll l=1,r=n;
	while(l<r){
		ll mid=(l+r+1)/2;
		if(check(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	for(ll i=l;i>=1;i--){
		if(check(i)){
			cout <<i;
			return 0;
		}
	}
	return 0;
}
