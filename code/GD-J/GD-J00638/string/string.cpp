#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,cnt,len1;
string s = "";
int is_hui(string x){
	int len = x.length();
	string tmp = x;
	x = "";
	for(ll i = len - 1;i >= 0;i--){
		x += tmp[i];
	}
	return tmp == x;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for(ll i = 1;i <= n;i++){
		ll a;
		char b;
		cin >> a >> b;
		for(ll i = 0;i < a;i++){
			s += b;
		}
	}
	ll len = s.length();
	if(is_hui(s)){
		cout << 0;
		return 0;
	}
	if(len % 2 == 0){
		len1 = len / 2;
	}
	else{
		len1 = (len - 1) / 2;
	}
	for(ll i = 0;i < len1;i++){
		ll p = len - i - 1;
		if(s[i] != s[p]) cnt++; 
	}
	cout << cnt;
	return 0;
}
