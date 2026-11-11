#include<bits/stdc++.h>
using namespace std;
int c[5],b[9];
string s[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c[1]>>s[1]>>c[2]>>s[2];
	if(c[1]==c[2])cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	if(s[1][0]==s[2][0]&&s[1][1]==s[2][1])cout<<"1";
	else{
		cout<<"000";
		return 0; 
	}
	if(s[1][2]=='A'||s[2][2]=='A')b[1]=1;
	if(s[1][2]=='B'||s[2][2]=='B')b[2]=1;
	if(s[1][2]=='C'||s[2][2]=='C')b[3]=1;
	if(s[1][2]=='D'||s[2][2]=='D')b[4]=1;
	if(s[1][2]=='F'||s[2][2]=='F')b[5]=1;
	if(b[4]+b[5]==2||b[1]+b[2]==2||b[2]+b[3]==2){
		cout<<"11";
		return 0;
	}
	else if(b[4]+b[5]==1){
		cout<<"00";
		return 0;
	}
	else cout<<"10";
	return 0;
}
