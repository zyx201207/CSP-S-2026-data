#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k;
string s,v;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=0;j<a;j++){
			s+=c;
		}
	}
	ll len = s.length();
	ll lenn = len-1;
	for(int i=0;i<len;i++){
		v+=s[lenn];
		lenn-=1;
	}
	if(v==s){
		cout<<"0";
	}else{
		len=len/2;
	}
	for(int i=0;i<len;i++){
		if(v[i]!=s[i]){
			k+=1;
		}
	}
	cout<<k;
	return 0;
}
