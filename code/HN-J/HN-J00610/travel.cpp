#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2; 
string s,a1,a2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0] && c1[1]==c2[1]) s+='1';
	else s+='0';
	if(s1[0]==s2[0] && s1[1]==s2[1] && s[0]=='1') s+='1';
	else s+='0';
	if(s1[2]>='A' && s1[2]<='c'){
		if(s2[2]>='A' && s2[2]<='C' && s[1]=='1'){
			s+='1';
		}else s+='0';
	}else if(s1[2]>='D' && s1[2]<='F'){
		if(s2[2]>='D' && s2[2]<='F'&& s[1]=='1'){
			s+='1';
		}else s+='0';
	}
	
	if(s1[2]-1==s2[2] || s1[2]+1==s2[2]){
		if(s[2]=='1') s+='1';
		else s+='0';
	}else s+='0';
	cout<<s;
	
	return 0;
} 
