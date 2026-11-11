#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char n[2];
	char m[2];
	char s[3];
	char t[3];
	for(int i=0;i<2;i++){
		cin>>n[i];
	}
	for(int i=0;i<3;i++){
		cin>>s[i];
	}
	for(int i=0;i<2;i++){
		cin>>m[i];
	}
	for(int i=0;i<3;i++){
		cin>>t[i];
	}
	if(n[0]==m[0]&&n[1]==m[1]){
		cout<<1;
	}
	else cout<<0;
	if(s[0]==t[0]&&s[1]==t[1]){
		cout<<1;
	}else cout<<0;
	if(s[2]-0>=65&&s[2]-0<=67){
		if(t[2]-0>=65&&t[2]-0<=67){
			cout<<1;
			if(t[2]+1==s[2]-0||t[2]-1==s[2]-0) cout<<1;
			else cout<<0;
		}else cout<<00;
	}else if(s[2]-0>=68&&s[2]-0<=69){
		if(t[2]-0>=68&&t[2]-0<=69) cout<<11;
	}
	return 0;
}
