#include<bits/stdc++.h>
using namespace std;
string ccf1,s1,ccf2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ccf1>>s1>>ccf2>>s2;
	if(ccf1!=ccf2){
		cout<<"0000";
		return 0;
	}
	if(s1[0]!=s2[0]){
		cout<<"1000";
		return 0;
	}
	if(s1[1]!=s2[1]){
		cout<<"1000";
		return 0;
	}
	cout<<"11";
	if(s1[2]=='A' && s2[2]=='B'||
	s1[2]=='B' && s2[2]=='C'||
	s1[2]=='D' && s2[2]=='F'||
	s2[2]=='A' && s1[2]=='B'||
	s2[2]=='B' && s1[2]=='C'||
	s2[2]=='D' && s1[2]=='F'){
		cout<<"11";
	}
	else if(s1[2]=='A'&&s2[2]=='C'||
	s2[2]=='A'&&s1[2]=='C'){
		cout<<"10";
	}
	else cout<<"00";
	return 0; 
}
