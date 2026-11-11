#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string S;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[1]==c2[1]){
		S[0]='1';
	}else{
		S[0]='0';
	}
	if(S[0]=='1'&&s1[1]==s2[1]&&s1[0]==s2[0]){
		S[1]='1';	
	}else{
		S[1]='0';
	}
	if((s1[2]<'D'&&s2[2]<'D'&&s1[2]>='A'&&s2[2]>='A'||s1[2]>='D'&&s2[2]>'D'&&s1[2]<='F'&&s2[2]<='F')&&S[0]=='1'&&S[1]=='1'){
		S[2]='1';
	}else{
		S[2]='0';
	}
	int a=s1[3]-65;
	int b=s2[3]-65;
	if(S[0]=='1'&&S[1]=='1'&&S[2]=='1'&&abs(a-b)==1){
		S[3]='1';
	}else{
		S[3]='0';
	}
	for(int i=0;i<=3;i++) cout<<S[i];
	return 0;
} 

