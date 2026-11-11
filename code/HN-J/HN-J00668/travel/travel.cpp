#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,c1,c2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		int flag=0;
		if(s1[1]==s2[1]&&s2[2]==s1[2])flag=1;
		if(flag==1){
			cout<<"1";
			if((s1[3]=='D'&&s2[3]!='C')||(s1[3]=='C'&&s2[3]!='D'))cout<<"0";
			else if((s1[3]=='D'&&s2[3]=='C')||(s1[3]=='C'&&s2[3]=='D'))cout<<"11";
			else {
				cout<<"1";
				if(s1[3]+'1'==s2[3]||s1[3]-'1'==s2[3])cout<<"1";
				else if(s1[3]==s2[3]&&(s1[1]==s2[1]&&s1[2]==s2[2]))cout<<"1";
				else cout<<"0";
				
			}
		}
		else {
			cout<<"000";
		}
	}
	else cout<<"0000";
	return 0;
}
