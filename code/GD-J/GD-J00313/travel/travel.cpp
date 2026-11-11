#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,ss;cin>>c1>>s1>>c2>>s2;int xx1,xx2;
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')xx1=0;
	else xx1=1;
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')xx2=0;
	else xx2=1;
	ss="0000";
	if(c1==c2)ss[0]='1';
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		ss[1]='1';
		if(xx2==xx1){
			ss[2]='1';
			if((s1[2]=='D'&&s2[2]=='E')||(s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')){
				ss[3]='1';
			}
		}
	}
	for(int i=0;i<4;i++)cout<<ss[i];
	return 0;
}
