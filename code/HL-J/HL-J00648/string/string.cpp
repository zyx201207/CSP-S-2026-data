#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	while(n--){
		ll x;
		char y;
		cin>>x>>y;
		for(ll i=1;i<=x;i++){
			s+=y;
		}
	}//Æ´½Ó

	ll cnt=0;
	ll r=s.size()-1;
		for(ll l=0;l<=s.size();l++){
		if(l<r){
			if(s[l]==s[r]){
				r--;
			   continue;
			}else {
				cnt++;
				r--;
			}
		}
	}
	cout<<cnt;
	return 0;
}
