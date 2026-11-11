#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define cin fin
#define cout fout
ifstream fin("and.in");
ofstream fout("and.out");
bool che(ll a,ll b){
	if(a!=b)return true;
	return false;
}
int main(){
	ll n,m;
	cin >> n >> m;
	vector<ll> a(n);
	
	ll mx=0;
	cin >> a[0];
	mx=max(mx,a[0]);
	ll ans=a[0];
	for(ll i=1;i<n;i++){
		cin >> a[i];
		mx=max(mx,a[i]);
		ans=(ans&a[i]);
	}
	
	if(m==1){
		cout << mx;
		return 0;
	}
	if(m==n){
		cout << ans;
		return 0;
	}
	if(m==2){
		ll mxx=0;
		for(ll i=0;i<n;i++){
			for(ll j=0;j<n;j++){
				if(i!=j){
					mxx=max((a[i]&a[j]),mxx);
				}
			}
		}
		cout << mxx;
		return 0;
	}
	
	
	return 0;
}
