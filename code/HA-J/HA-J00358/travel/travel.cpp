#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string s1,s2,c1,c2;
	string ans="";
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2) ans+="1";
	else ans+="0";
	
	if(s1.substr(0,2)==s2.substr(0,2)&&ans[0]!='0') ans+="1";
	else ans+="0";
	
	if((s1[2]>='A'&&s1[2]<='C'&&s1[2]>='A'&&s2[2]<='C'&&ans[1]!='0')
	||(s1[2]>='D'&&s1[2]<='F'&&s1[2]>='D'&&s2[2]<='F'&&ans[1]!='0')) ans+="1";
	else ans+="0";
	
	if(ans[2]=='0') ans+="0";
	else{
		if(s1[2]=='A'){
			if(s2[2]=='B') ans+="1";
			else ans+="0";
		}
		if(s1[2]=='B'){
			if(s2[2]=='A'||s2[2]=='C') ans+="1";
			else ans+="0";
		}
		if(s1[2]=='C'){
			if(s2[2]=='B') ans+="1";
			else ans+="0";
		}
		if(s1[2]=='D'){
			if(s2[2]=='F') ans+="1";
			else ans+="0";
		}
		if(s1[2]=='F'){
			if(s2[2]=='D') ans+="1";
			else ans+="0";
		}
	}
	
	cout<<ans<<endl;
	return 0;
}
