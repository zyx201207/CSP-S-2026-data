#include<bits/stdc++.h>
using namespace std;
int c[5];
char s[3][5];
int sn=0;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c[1]>>s[1][1]>>s[1][2]>>s[1][3];
	cin>>c[2]>>s[2][1]>>s[2][2]>>s[2][3];
	if(c[1]==c[2]){
		cout<<"1";
	}else {
		cout<<"0000";
		return 0;
	}
	if(s[1][2]==s[2][2]){
		cout<<"1";
	}else{ 
		cout<<"000";
		return 0;
	}
	
	if(s[1][3]<='C'&&s[2][3]<='C'){
		cout<<"1";
		if(s[1][3]-s[2][3]==1||s[1][3]-s[2][3]==-1){
			cout<<"1";
		}else sn+=1;
	}else if(s[1][3]>'C'&&s[1][3]<='F'&&s[2][3]>'C'&&s[2][3]<='F'){
		cout<<"1";
		if(s[1][3]-s[2][3]==2||s[1][3]-s[2][3]==-2){
			cout<<"1";
		}else sn+=1;
	}else{ 
		cout<<"0";
		sn+=1;
	}
	if(sn>0){
		cout<<"0";
	}
	return 0;
}