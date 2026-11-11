#include<iostream>
using namespace std;
using ll=long long;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="",a;
	ll n,x,ans=0;
	cin>>n;
	while(n--){
		cin>>x>>a;
		while(x--)s+=a;
	}
	for(ll i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1])ans++;
	}
	cout<<ans;
}
