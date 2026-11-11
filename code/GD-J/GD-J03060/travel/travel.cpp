#include <bits/stdc++.h>
using namespace std;
bool g(string s1,string s2){
	bool f=0;
	int s3,s4;
	s3=int(s1[0]+s1[1]);
	s4=int(s2[0]+s2[1]);
	if(((s1[2]=='C'&&s2[2]=='D')||(s2[2]=='C'&&s1[2]=='D'))){
		return f;
	}
	if((s3+1==s4||s4+1==s3)&&s1[2]==s2[2]){
		f=1;
	}
	if((s3==s4)&&(s1[2]+1==s2[2]||s1[2]==s2[2]+1)){
		f=1;
	}
	return f;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4,s5="";
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		s5+="1";
	}
	else{
		s5+="0";
	}
	if(s2[0]==s4[0]&&s2[1]==s4[1]&&s1==s3){
		s5+="1";
	}
	else{
		s5+="0";
	}
	if((s2[0]==s4[0]&&s2[1]==s4[1])&&((s2[2]>='D'&&s4[2]>='D')||(s2[2]<'D'&&s4[2]<'D'))&&s1==s3){
		s5+="1";
	}
	else{
		s5+="0"; 
	}
	if(g(s2,s4)&&s1==s3){
		s5+="1"; 
	}
	else{
		s5+="0";
	}
	cout<<s5;
	return 0;
} 
