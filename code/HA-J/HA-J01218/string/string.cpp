#include<bits/stdc++.h>
using namespace std;
map <char,long long > mp;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long c[200005];
	char d[200005];
	
	long long a;
	long long ma=-1;
	cin>>a;
	long long ct=0;
	int q=1,qq=1;
	for(int i=1;i<=a;i++){
		cin>>c[i]>>d[i];
		if(i>=2 and q==1){
			if(d[i]!=d[i-1])q=0;
		}
		ct+=c[i];
		mp[d[i]]+=c[i];
		ma=max(mp[d[i]],ma);
	}
	if(ma==ct){
		cout<<0;
		return 0;
	}
	if(ct%2==0){
		cout<<ct-ma;
		return 0;
	}
	if(ct%2==1){
		cout<<ct-ma-1;
		return 0;
	}
	return 0;
}