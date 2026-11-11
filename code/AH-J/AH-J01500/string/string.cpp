#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,s,cnt;
char c;
string b="";
ll hw(string a){
	string s="";
	for(ll i=a.size()-1;i>=0;i--){
		s+=a[i];
	}
	if(s==a){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>s>>c;
		for(ll j=1;j<=s;j++){
			b+=c;
		}
	}
	ll l=b.size();
	if(hw(b)==1){
		cout<<0;
		return 0;
	}
	else{
		if(l%2==0){
			for(ll i=0;i<sqrt(l);i++){
				if(b[i]!=b[l]+1-i){
					cnt++;
				}
			}
		}
		else{
			for(ll i=0;i<sqrt(l);i++){
				if(b[i]!=b[l]+1-i){
					cnt++;
				}
			}
		}
	}
	if(l%2!=0){
		cout<<cnt-1;
	}else{
		cout<<cnt;
	}
	return 0;
}
