#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll minn=1e18,len;
string rev(string s){
	string x;
	for(ll i=s.size()-1;i>=0;i--){
		x+=s[i];
	}
	return x;
}
void f(ll cnt,ll k,string x){
	if(k==len) return ;
	string l=rev(x);
	if(l==x){
		minn=min(minn,cnt);
		return ;
	}
	for(char c='a';c<='z';c++){
		if(x[k]==c){
			f(cnt,k+1,x);
		}
		else{
			x[k]=c;
			f(cnt+1,k+1,x);
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll t;
	cin>>t;
	while(t--){
		ll n;
		char c;
		cin>>n>>c;
		for(ll i=1;i<=n;i++) s+=c;
	}
	len=s.size();
	f(0,0,s);
	cout<<minn;
}
