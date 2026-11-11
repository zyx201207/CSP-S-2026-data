#include<bits/stdc++.h>
using namespace std;
int c,c2;
string s,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>c2>>s2;
	if(c==c2) cout<<'1';
	else if(c!=c2)cout<<"0000";
	else if(s[0]==s2[0] && s[1]==s2[1]) cout<<'1';
	else if(s[0]!=s2[0] || s[1]!=s2[1]) cout<<"000";
	else if((s[2]<='C' && s2[2]<='C')||(s[2]>'C' && s2[2]>'C')) cout<<'1';
	else if((s[2]>'C' && s2[2]<='C')||(s[2]<='C' && s2[2]>'C')) cout<<"00";
	else if(abs(s[2]-s2[2])==1) cout<<'1';
	else cout<<'0';
	return 0;
}
