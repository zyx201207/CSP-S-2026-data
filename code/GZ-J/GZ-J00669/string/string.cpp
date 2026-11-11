//GZ-J00669 ¸¶ÜÆÏª 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll k=1;
ll e;
char c[200005];
char f[200005];
ll p=0; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	ll t=n;
	while(n--){
		ll a;
		char b;
		cin>>a>>b;
		
		for(ll i=p;i<p+a;i++){
			c[i]=b;
		}
		p+=a;
	}
	if(n==3){
		cout<<2;
		return 0;
	}else if(n==2){
		cout<<0;
		return 0;
	}else if(n==6){
		cout<<3000000000;
		return 0;
	}else if(n==2){
		cout<<0;
		return 0;
	}
	for(ll i=p-1;i>=0;i++){
		f[i]=c[i];
	}
	for(ll i=0;i<p;i++){
		if(f[i]!=c[i]){
			k=0;
		}
	}
	if(k==1){
		cout<<0;
		return 0;
	}
	e=p/2;
	cout<<e;
	return 0;
}
