#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll t,j;
bool ihw(char s[]){
	ll l=0,r=j-1;
	while(l<r){
		if(s[l]==s[r]) l++,r--;
		else return false;
	}return true;
}int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>t;
	char s[2000005];
	while(t--){
		ll n;
		char a;
		cin>>n>>a;
		while(n--) s[j]=a,j++;
	}if(ihw(s)==true) cout<<0;
	else cout<<j/2;
	return 0;
}