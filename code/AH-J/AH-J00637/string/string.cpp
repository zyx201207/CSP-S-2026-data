#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s,s1;
	ll a,x;
	char q;
	cin>>a;
	while(a--){
		cin>>x;
		cin>>q;
		while(x--){
			s+=q;
		}
	}
	ll len=s.size(),ans=0;
	for(ll i=len-1;i>=len/2;i--){
		s1+=s[i];
	}
	for(ll i=0;i<len/2;i++){
		if(s[i]!=s1[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
