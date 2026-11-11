//GZ-j00638 遵义市第四初级中学  陈崇桓
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,f=0,m=0,x=0,l;
	cin>>n;
	int z[n];
	int v[n];
	for(int i=0;i<=n;++i){
		cin>>z[i]>>v[i];
	}
	string s;
	int d=s.length();
	for(int i=0;i<=d;++i){
		if(s[i]=='a'){
			f+=1;
		}if(s[i]=='b'){
			x+=1;
		}
	for(int i=0;i<=d;++i){
		if(s[i]!=s[d-i]){
			s[i]==s[d-i];
		l+=1;
		}
	}
	cout<<l;
	return 0;
}}



