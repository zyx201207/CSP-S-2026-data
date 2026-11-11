#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll m;
	string s="";
	cin >> m;
	while(m--){
		ll a;
		char b;
		cin >> a >> b;
		for(ll i=1;i<=a;i++){
			s+=b;
		}
	}
	ll n=s.size();
	ll cnt=0;
	string tmp=s;
	reverse(tmp.begin(),tmp.end());
	if(tmp==s){
		cout << 0;
		return 0;
	}
	if(n%2==0){
		ll cen=n/2;
		for(ll i=cen;i<n;i++){
			if(tmp[i]!=s[i])cnt++;
		}
	}else{
		ll cen=n/2+1;
		for(ll i=cen;i<n;i++){
			if(tmp[i]!=s[i])cnt++;
		}
	}
	cout << cnt;
	return 0;
}