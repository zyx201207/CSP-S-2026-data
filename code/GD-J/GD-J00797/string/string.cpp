#include<iostream>
#include<string>
#include<cstring>
typedef long long ll;
using namespace std;
ll n,l=0,all=0;
string s="";
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=0;i<n;i++){
		ll a;
		char c;
		cin>>a>>c;
		l+=a;
		for(ll j=0;j<a;j++){
			s+=c;
		}
	}
	for(ll i=0;i<l;i++){
		if(s[i]!=s[l-i-1])all++;
	} 
	all/=2;
	cout<<all<<'\n';
	return 0;
}
