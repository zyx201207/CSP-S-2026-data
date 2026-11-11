#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		ll x;
		string c;
		cin>>x>>c;
		for(ll j=1;j<=x;j++){
			s+=c;
		}
	}
	ll l=0,r=s.size()-1;
	while(l<=r){
		if(s[l]==s[r]){
			l+=1;
			r-=1;
		}else{
			l+=1;
			r-=1;
			ans++;
		}
	}
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);	
} 
