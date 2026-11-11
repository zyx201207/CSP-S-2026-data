#include<bits/stdc++.h>
using namespace std;
string a,b,c,e;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c >> e;
	if(a!=c){ 
		cout<<"0000";
		return 0;
	}else{
		cout<<1;
	}
	if((b[0]==e[0]) && (b[1] == e[1])){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(e[2]=='D'||e[2]=='F'))||((e[2]=='A'||e[2]=='B'||e[2]=='C')&&(b[2]=='D'||b[2]=='F'))){
		cout<<"00";
		return 0;
	}else{
		cout<<1;
	}
	if(((b[2]=='A')&&(e[2]=='B'))||(b[2]=='B'&&(e[2]=='C'||e[2]=='A'))||(b[2]=='C'&&e[2]=='B')||(b[2]=='D'&&e[2]=='F')||(b[2]=='F'&&e[2]=='D')){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
