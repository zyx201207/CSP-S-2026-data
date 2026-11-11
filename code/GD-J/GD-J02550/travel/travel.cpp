#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int s1_int,s2_int,c_int;
	char s1[3],s2[3],c1[2],c2[2];
	bool flag=true;
	cin>>c1[1]>>c1[2]>>s1[1]>>s1[2]>>s1[3]>>c2[1]>>c2[2]>>s2[1]>>s2[2]>>s2[3];
	if(c1[1]==c2[1] && c1[2]==c2[2]){
		cout<<'1'; 
	}else{
		cout<<"0000";
		return 0;
	}
	
	if(s1[1]==s2[1] && s1[2]==s2[2]) cout<<'1';
	else {
		cout<<'0';
		flag=false;
	}
	
	s1_int=s1[3];
	s2_int=s2[3];
	c_int='C';
	if(s1_int>c_int) s1_int++;
	if(s2_int>c_int) s2_int++;
	
	if(s1[3]=='A' || s1[3]=='B' || s1[3]=='C') s1[3]=1;
	else if(s1[3]=='C' || s1[3]=='D')s1[3]=0;
	if(s2[3]=='A' || s2[3]=='B' || s2[3]=='C') s2[3]=1;
	else if(s2[3]=='C' || s2[3]=='D')s2[3]=0;
	if(s1[3]==s2[3] && flag){
		cout<<'1';
		int s1_s2=abs(s1_int-s2_int);
		if(s1_s2!=1) cout<<'0';
		else cout<<'1';
	}else cout<<"00";
	
	
	return 0;
} 
