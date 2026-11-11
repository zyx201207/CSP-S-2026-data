#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if(cc==c) cout<<1;
	else {
		cout<<"0000";
		return 0;
	}
	if(s.substr(0,2)==ss.substr(0,2)) cout<<1;
	else {
		cout<<"000";
		return 0;
	}
	if((s[2]=='A'||s[2]=='B'||s[2]=='C')&&(ss[2]=='A'||ss[2]=='B'||ss[2]=='C')){
	cout<<1;	
	}
	else if((s[2]=='D'||s[2]=='F')&&(ss[2]=='F'||ss[2]=='D'))
	cout<<1;
	else {
	cout<<"00";
	return 0;	
	}
	if((s[2]=='A'&&ss[2]=='B')||(s[2]=='B'&&ss[2]=='C')||(s[2]=='D'&&ss[2]=='F'))
	cout<<1;
	else cout<<0;
	return 0;
}
