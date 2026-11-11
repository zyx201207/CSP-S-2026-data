#include<bits/stdc++.h>
using namespace std;
int an,bn;
string as,bs;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>an>>as>>bn>>bs;
	if(an==bn)cout<<1;
	else{
		cout<<"0000";
		return 0; 
	}if(as[0]==bs[0]&&as[1]==bs[1])cout<<1;
	else{
		cout<<"000";
		return 0;
	}if((as[2]<='C'&&bs[2]<='C')||(as[2]>'C'&&bs[2]>'C'))cout<<1;
	else{
		cout<<"00";
		return 0;
	}if(as[2]>'C'&&bs[2]>'C')cout<<1;
	else if((as[2]<='C'&&bs[2]<='C')&&((as[2]=='A'&&bs[2]=='B')||(as[2]=='B'&&bs[2]=='C')||(as[2]=='B'&&bs[2]=='A')))cout<<1;
	else cout<<0; 
	return 0;
} 
