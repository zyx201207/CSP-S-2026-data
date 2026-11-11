#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[10000005],sum;
char c[10000005];
ll check(string s){
	ll l=0,r=s.size()-1;
	while(l<=r){
		if(s[l]!=s[r])sum++;
		l++,r--;
	}
	return sum;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	string s="";
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	cout<<check(s);
	
	
	return 0;
}
