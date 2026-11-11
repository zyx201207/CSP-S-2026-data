#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		ll a;
		cin>>a;
		string c;
		cin>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	ll l=0,r=s.size()-1;
	while(l<=r){
		if(s[l]==s[r]){
			l++;
			r--;
		}else{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
