#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s11,s2,s22;
	cin>>s1>>s11>>s2>>s22;
	if(s1==s2){
		if((s11[0]==s22[0])&&(s11[1]==s22[1])){
			if((s11[2]=='A')||(s11[2]=='B')||(s11[2]=='C')&&(s22[2]=='A')||(s22[2]=='B')||(s22[2]=='C')&&(s11[2]!=s22[2])){
				if((s11[2]=='A'&&s22[2]=='B')||(s11[2]=='B'&&s22[2]=='A')||(s11[2]=='B'&&s22[2]=='C')||(s11[2]=='C'&&s22[2]=='B')){
					cout<<"1111";
				}
				else cout<<"1110";
			}
			else if((s11[2]=='F'&&s11[2]=='D')||(s22[2]=='F'&&s22[2]=='D')){
				cout<<"1111";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
		
	}
	else cout<<"0000";
	return 0;
}
