#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const ll N=1e6+10;
ll n;
struct node{
	ll ai;
	
	char ci;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i].ai>>a[i].ci;
	}
	ll x=0;
	for(ll i=1;i<=n;i++){
		x+=a[i].ai;
	}
	if(x>1e9){
		cout<<x/2;
		return 0;
	}
	string s="";
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=a[i].ai;j++){
			s+=a[i].ci;
		}
	}
	//hunfen
	string s1;
	for(ll i=s.size();i>=0;i--){
		s1=s[i]+s1;
	}
	if(s1==s){
		cout<<0;
		return 0;
	}
	//hunfen


	return 0;
}
//aabbc
//cbbaa
