#include<bits/stdc++.h>
#define Y(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;
string c1,s1,c2,s2,ans;
int main(){
	Y("travel");
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans+="1";
		if(s1.substr(0,2)==s2.substr(0,2))ans+="1";
		else ans+="0";
		if(s1.substr(0,2)==s2.substr(0,2)){
			if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))ans+="1";
			else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))ans+="1";
			else ans+="0";
			if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C'))||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))ans+="1";
			else ans+="0";
		}
		else ans+="00";
	}
	else ans="0000";
	cout<<ans;
}
//Trick||Treat!
