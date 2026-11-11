#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,s1,s2,s3;
	cin>>s>>s1>>s2>>s3;
    if(s[0]==s2[0]&&s[1]==s2[1]){
    	cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s3[0]&&s1[1]==s3[1]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	bool cnp=false;
	if((s1[2]=='F'&&s3[2]=='D')||(s1[2]=='D'&&s3[2]=='F'))
	{
		cnp=true;
		cout<<"1";
	}
	if((s1[2]=='A'&&s3[2]=='B')||(s1[2]=='B'&&s3[2]=='A')){
		cnp=true;
		cout<<"1";
	}
	if(((s1[2]=='C'&&s3[2]=='B')||(s1[2]=='B'&&s3[2]=='C'))||((s1[2]=='A'&&s3[2]=='C')||(s1[2]=='C'&&s3[2]=='A'))){
	    cnp=true;
		cout<<"1";
	}
	if(!cnp){
		cout<<"00";
		return 0;
	}
	if((s1[2]=='A'&&s3[2]=='C')||(s1[2]=='C'&&s3[2]=='A')){
		cout<<"0";
	}else{
		cout<<"1";
	}
	return 0;
}
