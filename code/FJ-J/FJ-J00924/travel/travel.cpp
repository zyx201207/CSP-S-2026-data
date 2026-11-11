#include<bits/stdc++.h>
using namespace std;
string c,s,C,S;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>C>>S;
	if(c==C){
		cout<<1; 
	}else{
		cout<<"0000";
		return 0;
	}
	if(s[0]==S[0]&&s[1]==S[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	char ch=s[2],Ch=S[2];
	if((ch<='C'&&Ch<='C')||(ch>='D'&&Ch>='D')){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(!((ch=='A'&&Ch=='C')||(Ch=='A'&&ch=='C'))){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
