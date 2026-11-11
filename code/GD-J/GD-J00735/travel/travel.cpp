#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2;
	bool flag1=0,flag2=0,flag3=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		flag3=1;
		cout<<"1";
	} 
	else{
		cout<<"0";
	}
	
	if((s1[0]==s2[0]&&s1[1]==s2[1])&&flag3==1){
		flag1=1;
		cout<<"1";
	} 
	else{
		cout<<"0";
	} 
	
	if(((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'))&&flag1==1){
		cout<<"1";
		flag2=1;
	} 
	else{
		cout<<"0";
	} 
	
	
	if((s1[2]==s2[2]+1||s2[2]==s1[2]+1)&&flag2==1) cout<<"1";
	else cout<<"0";
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

