#include<bits/stdc++.h>
using namespace std;
string s[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s[1]>>s[2]>>s[3]>>s[4];
	if(s[1]==s[3]){
		if(s[2][0]==s[4][0]&&s[2][1]==s[4][1]){
			if((s[2][2]=='A'||s[2][2]=='B'||s[2][2]=='C')&&(s[4][2]=='A'||s[4][2]=='B'||s[4][2]=='C')){
				if(abs(s[2][2]-s[4][2])==1) cout<<"1111";
				else cout<<"1110";
			}else if((s[2][2]=='D'||s[2][2]=='F')&&(s[4][2]=='D'||s[4][2]=='F')){
				if(abs(s[2][2]-s[4][2])==1) cout<<"1111";
				else cout<<"1110";
			}else cout<<"1100";
		}else cout<<"1000";
	}else cout<<"0000";
}
