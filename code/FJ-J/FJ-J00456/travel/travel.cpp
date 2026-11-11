#include<bits/stdc++.h>
using namespace std;

freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
int main(){
	string c1;
	string s1;
	string c2;
	string s2;
	string a;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) a+='1';
	else{
	cout<<"0000";
	return 0;}
	if(s1[0]==s2[0]&&s1[1]==s2[1])
	a+='1';
	else a+='0';
	if(s1[2]-s2[2]<=1){
	
		if((s1[2]=='C'||s1[2]=='D')&&(s2[2]=='C'||s2[2]=='D'))
	a+='0';
	else a+='1';}
	if(s1[2]-s2[2]==1&&(s1[2]=='C'||s1[2]=='D')&&(s2[2]=='C'||s2[2]=='D')) a+='1';
	else a+='0';
	
	cout<<a;
	
	
	
	return 0;
	
}

