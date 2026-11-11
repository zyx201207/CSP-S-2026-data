#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a;
char ch;
string s;
bool hw(string s){
	string t=s;
	reverse(s.begin(),s.end());
	return t==s;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a;
		cin>>ch;
		for(ll i=1;i<=a;i++){
			s+=ch;
		}
	}
	ll ans=0;
	if(hw(s)){
		cout<<0;
	}else{
		ll l=0,r=s.size()-1;
		while(l<r){
			if(s[l]!=s[r]){
				ans++;
				s[r]=s[l];
			}
			l++;
			r--;
		}
		cout<<ans;
	}
	
	return 0;
}
