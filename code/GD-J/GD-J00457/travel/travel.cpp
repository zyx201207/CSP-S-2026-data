#include<iostream>
#include<cmath>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4,s5="";cin>>s1>>s2>>s3>>s4;
	if(s1==s3) s5+='1';
	else s5+='0';
	
	if(s1==s3 && s2[0]==s4[0] && s2[1]==s4[1]) s5+='1';
	else s5+='0';
	
	if(s1==s3 && s2[0]==s4[0] && s2[1]==s4[1] && ((s2[2]<='C' && s4[2]<='C') || (s2[2]>='D' && s4[2]>='D'))) s5+='1';
	else s5+='0';
	
	if(s1==s3 && s2[0]==s4[0] && s2[1]==s4[1] && ((s2[2]<='C' && s4[2]<='C') || (s2[2]>='D' && s4[2]>='D')) && abs(s2[2]-s4[2])==1) s5+='1';
	else s5+='0';
	
	cout<<s5;
}
