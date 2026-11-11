#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s[5];
	cin>>s[1]>>s[2]>>s[3]>>s[4];
	if(s[1]==s[3]){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(s[2][0]==s[4][0]&&s[2][1]==s[4][1]){
		cout<<"1";
	}else{
		cout<<"0";
	}
	int bj=0;
	if((((s[2][2]=='A'||s[2][2]=='B'||s[2][2]=='C')&&(s[4][2]=='A'||s[4][2]=='B'||s[4][2]=='C'))||((s[2][2]=='D'||s[2][2]=='F')&&(s[4][2]=='D'||s[4][2]=='F')))&&s[2][0]==s[4][0]&&s[2][1]==s[4][1]){
		cout<<"1";
		bj=1;
	}else{
		cout<<"0";
	}
	if(bj&&(char(s[2][2]-1)==s[4][2]||char(s[2][2]+1)==s[4][2])){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
} 
