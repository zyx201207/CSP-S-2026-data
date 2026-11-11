#include<bits/stdc++.h>
using namespace std;
string s[5];
string s1[5];

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s[0];
	cin>>s[1];
	cin>>s1[0];
	cin>>s1[1];
	if(s[0]==s1[0]){
		cout<<"1";
		if(s[0]==s1[0]&&s[1][0]==s1[1][0]&&s[1][1]==s1[1][1]){
			cout<<"1";
			if((s[1][2]<='C'&&s[1][2]>='A'&&s1[1][2]<='C'&&s1[1][2]>='A')||((s[1][2]=='F'&&s1[1][2]=='F')||(s[1][2]=='D'&&s1[1][2]=='D'))){
				cout<<"1";
				if(s[1][2]<='C'&&s[1][2]>='A'&&s1[1][2]<='C'&&s1[1][2]>='A'&&(s[1][2]==s1[1][2]+1||s1[1][2]==s[1][2]+1)){
					cout<<"1";
				}else if((s[1][2]=='F'&&s1[1][2]=='F')||(s[1][2]=='D'&&s1[1][2]=='D')){
					cout<<"1";
				}else {
					cout<<"0";
				}
			}else {
				cout<<"00";
			}
		}else {
			cout<<"000";
		}
	}else {
		cout<<"0000";
	}
	return 0;
} 
