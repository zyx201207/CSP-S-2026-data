#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int k=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0";k=1;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&k!=1){
		cout<<"1";
	}else{
		cout<<"0";k=1;
	}
	if(((s1[2]>='A'&&s2[2]>='A'&&s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'&&s1[2]<='E'&&s2[2]<='E'))&&k!=1){
		cout<<"1";
	}else{
		cout<<"0";k=1;
	}
	if(((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='E')||(s2[2]=='A'&&s1[2]=='B')||(s2[2]=='B'&&s1[2]=='C')||(s2[2]=='D'&&s1[2]=='E'))&&k!=1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
