#include<bits/stdc++.h>
using namespace std;
using ll=long long;
string s="";
int main(){
	freopen("string.in" ,"r", stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	ll n,m=0,ns=0;cin>>n;
	for(ll i=0;i<n;i++){
		ll x;char c;
		cin>>x>>c;
		for(ll j=0;j<x;j++)
			s+=c;
		m+=x;
	}
	ll end=m/2+m%2;m--;
	for(int i=0;i<=end;i++)
		if(s[i]!=s[m-i]) ns++;
	cout<<ns;
	return 0;
}