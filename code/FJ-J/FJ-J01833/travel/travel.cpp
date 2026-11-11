#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
bool book=false;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3)
		cout<<1;
	else{
		cout<<"0000";
		return 0;
	}	
	if(s2[0]==s4[0]&&s2[1]==s2[1]&&book==false)
		cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if(((s2[2]=='A'&&s4[2]=='D')||(s2[2]=='A'&&s4[2]=='E')||(s2[2]=='B'&&s4[2]=='D')||(s2[2]=='B'&&s4[2]=='E')||(s2[2]=='C'&&s4[2]=='D')||(s2[2]=='C'&&s4[2]=='E')||(s4[2]=='A'&&s2[2]=='D')||(s4[2]=='A'&&s2[2]=='E')||(s4[2]=='B'&&s2[2]=='D')||(s4[2]=='B'&&s2[2]=='E')||(s4[2]=='C'&&s2[2]=='D')||(s4[2]=='C'&&s2[2]=='E'))){
		cout<<"00";
		return 0;
	}else
		cout<<"1";

	if(abs(s2[2]-s4[2])==1)
		cout<<"1";
	else
		cout<<"0";
	return 0;
} 
