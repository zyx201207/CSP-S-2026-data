#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(s1[2]=='A') s1[2]='1';
	if(s1[2]=='B') s1[2]='2';
	if(s1[2]=='C') s1[2]='3';
	if(s1[2]=='D') s1[2]='4';
	if(s1[2]=='E') s1[2]='5';
	if(s2[2]=='A') s2[2]='1';
	if(s2[2]=='B') s2[2]='2';
	if(s2[2]=='C') s2[2]='3';
	if(s2[2]=='D') s2[2]='4';
	if(s2[2]=='E') s2[2]='5';
	if(c1==c2){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			if((s1[2]-'0'<=3&&s2[2]-'0'<=3)||(s1[2]-'0'>=4&&s2[2]-'0'>=4)){
				cout<<"1";
				if(abs(s1[2]-s2[2])==1&&s1[2]-'0'+s2[2]-'0'!=7){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
