#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,mid,lans,rans,tsz;
ll a[10005];
char c[10005];
string s,l,r;
bool gn(string a){
	for(ll i=0,j=a.size()-1;i<j;i++,j--){
		if(a[i]!=a[j]) return 0;
	}
	return 1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>a[i]>>c[i];
		s.push_back(c[i]);
	}
	if(gn(s)){
		cout<<0;
		return 0;
	}
	mid=(s.size())/2;
	for(ll i=0;i<=mid;i++) l.push_back(s[i]);
	for(ll i=mid;i<s.size();i++) r.push_back(s[i]);
	for(ll i=0;i<=mid;i++) if(r[i+mid]!=l[i]) lans+=a[i];
	for(ll i=0;i<mid;i++) if(l[i-mid]!=r[i]) rans+=a[i];
	cout<<min(lans,rans);
	return 0;
}
/*
3
2 a
2 b
1 c

abasg
ab sg

ababa 
*/
