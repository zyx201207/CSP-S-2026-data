#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int main(){
	freopen("travel5.in","r",stdin);
	freopen("travel5.out","w",stdout);
	string c1,c2,s1,s2;
	string anser="0000";
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		anser[0]='1';
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			anser[1]='1';
			if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))){
				anser[2]='1';
				if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C'))||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
					anser[3]='1';
				}
			}
		}
	}
	cout<<anser;
	return 0;
}

