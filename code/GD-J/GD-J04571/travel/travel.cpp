#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,s,t;
	cin>>a>>t>>b>>s;
	if(a==b) cout<<1;
	else{
		cout<<"0000";
		return 0;
	} 
	if((s[0]-'0')*10+(s[1]-'0')==(t[0]-'0')*10+(t[1]-'0')) cout<<1;
	else{
		cout<<"000";
		return 0;
	} 
	if(s[2]<='C'&&t[2]<='C'||s[2]>'C'&&t[2]>'C') cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(abs(s[2]-t[2])==1) cout<<1;
	else cout<<0;
	return 0;
} 
