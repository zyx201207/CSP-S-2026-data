#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
	ll n;
	cin>>n;
	ll ans=0;
	vector<ll>a(n+1);
	vector<char>c(n+1);
	ll num=0;
	for(ll i = 1; i <= n; i ++){
		cin>>a[i]>>c[i];
		num+=a[i];
	}
	if(num%2){
		ll p=0;
		for(ll i = 1; i <= n; i ++){
			p+=a[i];
			if(p>=num/2+1){
				a[i]--;
				break;
			}
		}
		num--;
	}
	ll l = 1, r = n, L = 0, R = 0;
	char cl='a', cr='a';
	while(l<=r){
		if(L<R){
//			cout<<'l';
			ll dl = L+a[l];
			if(c[l]!=cr){
				ans+=min(dl,R)-L;
			}
			L = dl;
			cl=c[l];
			l++;
		}
		else{
//			cout<<'r';
			ll dr = R+a[r];
			if(c[r]!=cl){
				ans+=min(dr,L)-R;
			}
			R = dr;
			cr=c[r];
			r--;
		}
	}
	cout<<ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
} 
