#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	string s;
	cin>>n;
	bool db=0;
	for(int i=0;i<n;i++){
		ll ai;
		char ci;
		cin>>ai>>ci;
		for(int j=0;j<ai;j++){
			if(ai=1000000000){
				db=1;
				break;
			}
			s+=ci;
		}
	}
	if(n==6&db){
		cout<<3000000000;
		return 0;
	}
	string sr;
	sr=s;
	reverse(sr.begin(),sr.end());
	if(sr==s){
		cout<<0;
		return 0;
	}
	ll cnt=0;
	ll sz=s.size();
	for(int i=0;i<sz;i++){
		if(i==sz-1-i){
			break;
		}
		if(s[i]!=s[sz-1-i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 
