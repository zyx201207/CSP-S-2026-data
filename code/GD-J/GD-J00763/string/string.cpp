#include<bits/stdc++.h>
using namespace std;
using ll=long long;
string x,y;
bool p,l,r,e,u;
ll n,o;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	ll l=n;
	x+=' ';
	y+=' ';
	while(n--){
		ll m;
		char s;
		cin>>m>>s;
		while(m--){
			x+=s;
		}
		
	}
	for(ll i=x.size()-1;i>=x.size()/2;i--){
		char d=x[i];
		y+=d;
	}
	for(ll i=1;i<=x.size()/2;i++){
		if(x[i]!=y[i])o++;
	}cout<<o;
	return 0;
}
