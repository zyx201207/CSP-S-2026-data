#include<bits/stdc++.h>
using namespace std;
string s,s1,s2,s3;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>s1>>s2>>s3;
	if(s==s2){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}	
	if(s1[0]==s3[0]&&s1[1]==s3[1]){
		cout<<1;
	}
	else{
		cout<<0;
	}
	bool f=1,op=1;
	if(s1[0]==s3[0]&&s1[1]==s3[1]){
		if((s1[2]=='A'&&s3[2]=='D')||(s1[2]=='A'&&s3[2]=='F')||(s1[2]=='B'&&s3[2]=='D')||(s1[2]=='B'&&s3[2]=='F')||(s1[2]=='C'&&s3[2]=='D')||(s1[2]=='C'&&s3[2]=='F')){
			f=0,op=0;
		    cout<<0;
	    }
	}
	if(s1[0]==s3[0]&&s1[1]==s3[1]&&op==1){
		cout<<1;
	}
	if(!(s1[0]==s3[0]&&s1[1]==s3[1])&&op==1){
		f=0;
		cout<<0;
	}
	if((s1[2]+1==s3[2]||s1[2]-1==s3[2])&&f){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
