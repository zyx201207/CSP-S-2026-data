#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
const int N = 2e5+5;
ll n,ans;
string s,ss;
void init(){
	ll temp=s.size()-1;
	for(ll i=0;i<s.size();i++){
		if(s[i]==s[temp-i]){
			continue;
		}
		else ans++;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++){
		ll sz;cin>>sz;
		char c; cin>>c;
		for(ll j=1;j<=sz;j++) {
			s+=c;
		}
	}
	init();
	cout<<ans/2;
	return 0;
}


//6
//1000000000 a
//1000000000 a
//1000000000 a
//1000000000 b
//1000000000 b
//1000000000 b


//3
//2 a
//2 b
//1 c
