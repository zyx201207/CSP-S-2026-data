#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s,ss;
ll n,a,lasta;
char b,lastb;
bool hw(string s){
	string ss=s;
	reverse(ss.begin(),ss.end());
	if(ss==s)return 1;
	return 0;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a>>b;
		while(a--){
			s+=b;
	    }
	}
	if(hw(s)){
		cout<<0;
		return 0;
	}
	ll len=s.size(),cnt=0;
	for(ll i=0;i<len/2;i++){
		ll x=s[i+len-1];
		if(x!=s[i])cnt++;
	}
	cout<<cnt;
	return 0;
}
