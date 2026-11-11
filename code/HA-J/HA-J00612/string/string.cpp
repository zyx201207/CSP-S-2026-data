#include<bits/stdc++.h>
using namespace std;
using ll=long long;
bool f=0;
ll cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string w="",x="",y="";
	ll h;cin>>h;
	for(int i=1;i<=h;i++){
		ll a; string b;
		cin>>a>>b;
		while(a--) w+=b;
	}
	if(w.size()%2==1) f=1;
	ll n=w.size()/2;
	x=w.substr(0,n);
	if(f) y=w.substr(n+1,n);
	else y=w.substr(n,n);
	for(int i=0;i<n;i++){
		if(x[i]!=y[i]) cnt++;
	}
	cout<<cnt;
	return 0;
}