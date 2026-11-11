#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	ll n;
	cin>>n;
	string s;
	for(ll i=1;i<=n;i++){
		ll a;
		char c;
		cin>>a>>c;
		for(ll i=1;i<=a;i++) s+=c;
	}
	ll ans=s.size();
	ll mid=0,j=1;
	if(ans%2==0) mid=ans/2;
	else mid=ans/2+1;
	ll o=ans-mid;
	for(ll i=mid;i<=ans;i++){
		if(s[i]==s[j]) o--;
		j++;
	}
	cout<<o;

	return 0;
}
