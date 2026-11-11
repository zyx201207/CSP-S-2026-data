#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define cin fin
#define cout fout
ifstream fin("string.in");
ofstream fout("string.out");
int main(){
	ll n;
	cin >> n;
	ll shu;
	char ch;
	string s="";
	if(n==1){
		cout << 0;
		return 0;
	}
	for(ll i=0;i<n;i++){
		cin >> shu >> ch;
		for(ll j=0;j<shu;j++){
			s+=ch;
		}
	}
	
	ll ans=0;
	for(ll i=0;i<s.size();i++){
		if(s[i]!=s[s.size()-1-i]){
			ans++;
			s[s.size()-1-i]=s[i];
		}
	}
	cout << ans;
	return 0;
}
