#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string s;
int t;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	ll cnt = 0;
	while(t--){
		ll n;
		string word;
		cin>>n>>word;
		//cout<<n<<" "<<word<<"\n"; 
		for(int i = 1 ; i <= n ; i ++){
			s += word;
			cnt ++;
		}
	}
	//cout<<s<<"\n";
	ll l = 0 , r = cnt - 1;
	ll ans = 0;
	while(l <= r){
		if(s[l] != s[r]) ans++;
		l++,r--;
	} 
	cout<<ans;
	return 0;
}
