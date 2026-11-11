#include<bits/stdc++.h>
using namespace std;
using ll=long long;
bool check(char a,char b){
	if(a=='F'&&b=='D') return 1;
	else if(a=='D'&&b=='F') return 1;
	else if(a>='A'&&a<='C'&&b>='A'&&b<='C'){
		return 1;
	}
	return 0;
}
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	ll r=0,x=0;
	for(ll i=a.size()-1;i>=0;i--){
		r=r*10+(a[i]-'0');
	}
	for(ll i=c.size()-1;i>=0;i--){
		x=x*10+(c[i]-'0');
	}
	if(r!=x){
		cout<<"0000";
		return 0;
	}
	r=0,x=0;
	for(ll i=b.size()-2;i>=0;i--){
		r=r*10+(b[i]-'0');
	}
	for(ll i=d.size()-2;i>=0;i--){
		x=x*10+(d[i]-'0');
	}
	if(r!=x){
		cout<<"1000";
		return 0;
	}
	if(check(char(b[2]),char(d[2]))==0){
		cout<<"1100";
		return 0;
	}
	if(abs(ll(b[2])-ll(d[2]))!=1){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
