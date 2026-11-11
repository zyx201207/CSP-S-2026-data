#include<bits/stdc++.h>
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,s,a,b;
	int flag=1;
	cin>>c>>s>>a>>b;
	c+=' ';
	s+=' ';
	a+=' ';
	b+=' ';
	if(c==a){
		cout<<"1";
	}else{
		cout<<"0000";
		flag=0;
	}
	if(flag){
		if(s[0]==b[0]&&s[1]==b[1]){
			cout<<"1";
		}else{
			cout<<"000";
			flag=0;
		}
	}
	if(flag){
		if(s[2]=='D'&&b[2]=='F'||s[2]=='F'&&b[2]=='D'||s[2]!='D'&&b[2]!='F'&&s[2]!='F'&&b[2]!='D'){
			cout<<"1";
		}else{
			cout<<"00";
			flag=0;
		}
	}
	if(flag){
		if(s[2]=='A'&&b[2]=='B'||s[2]=='B'&&b[2]=='A'||s[2]=='C'&&b[2]=='B'||s[2]=='B'&&b[2]=='C'||s[2]=='D'&&b[2]=='F'||s[2]=='F'&&b[2]=='D'){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}
	return 0; 
}

