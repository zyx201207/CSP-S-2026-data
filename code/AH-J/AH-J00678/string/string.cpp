#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	if(n==1) cout<<0;
	ll a;string s,ss;
	for(ll i=1;i<=n;i++){
		cin>>a>>ss;
		for(ll i=1;i<=a;i++) s+=ss;
	}
	ll l=0,r=s.size()-1,cnt=0;
	while(l<=r){
		if(s[l]!=s[r]) cnt++;
		l++,r--;
	}
	cout<<cnt;
	return 0;
}
