#include<bits/stdc++.h>
using namespace std;
int main(){//100
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	string s[6];
	cin>>s[0]>>s[1]>>s[2]>>s[3];	
	if(s[0]==s[2]&&s[0]!="1"&&s[0]!="16"){
		cout<<1;
	}
	else{
		cout<<0;
	}	
	if(s[0]==s[2]&&s[0]!="1"&&s[0]!="16"&&s[1][0]==s[3][0]&&s[1][1]==s[3][1]){//para2
		cout<<1;
	}
	else{
		cout<<0;
	}
	char ca=min(s[1][2],s[3][2]);
	char cb=max(s[1][2],s[3][2]);
	if(s[0]==s[2]&&s[0]!="1"&&s[0]!="16"&&s[1][0]==s[3][0]&&s[1][1]==s[3][1]&&((ca=='D'&&cb=='F')||(ca=='B'&&cb=='C')||(ca=='A'&&cb=='B')||(ca=='A'&&cb=='C'))){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(s[0]==s[2]&&s[0]!="1"&&s[0]!="16"&&s[1][0]==s[3][0]&&s[1][1]==s[3][1]&&((ca=='D'&&cb=='F')||(ca=='B'&&cb=='C')||(ca=='A'&&cb=='B'))){//para4
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
