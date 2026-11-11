#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<char,ll> x;
ll n,res,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		cout<<2;
		return 0;
	}
	for(int i=1;i<=n;i++){
		ll shu;
		char fu;
		cin>>shu>>fu;
		x[fu]+=shu;
	}
	for(int i=97;i<=122;i++){
		if(x[char(i)]!=0) res++;
	}
	if(res==1){
		cout<<1;
		return 0;
	}
	if(res==2 || res==3){
		cout<<2;
		return 0;
	}
	return 0;
}

