#include<bits/stdc++.h>
using namespace std;
char s[5][5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s[1]>>s[2]>>s[3]>>s[4];
	if(s[1][0]==s[3][0]&&s[1][1]==s[3][1]){
		cout<<"1";
		if(s[2][0]==s[4][0]&&s[2][1]==s[4][1]){
			cout<<"1";
			if(s[2][2]=='A'||s[2][2]=='B'||s[2][2]=='C'){
				if(s[4][2]=='A'||s[4][2]=='B'||s[4][2]=='C'){
					cout<<"1";
					if(s[4][2]-1==s[2][2]||s[4][2]+1==s[2][2]){
						cout<<"1";
					}else{
						cout<<"0";
					} 
				}else{
					cout<<"00";
				}
			}
			if(s[2][2]=='D'||s[2][2]=='F'){
				if(s[4][2]=='D'||s[4][2]=='F'){
					cout<<"11";
				}else{
					cout<<"00";
				}
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
