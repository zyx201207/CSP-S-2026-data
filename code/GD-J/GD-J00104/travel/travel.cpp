#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
string c1,s1,c2,s2;
int cc1=0,ss1=0,cc2=0,ss2=0;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>c1>>s1>>c2>>s2;
for(int i=0;i<2;i++){
	cc1*=10;
	cc1+=c1[i]-'0';
}
for(int i=0;i<2;i++){
	cc2*=10;
	cc2+=c2[i]-'0';
}
if(cc1==cc2){
	for(int i=0;i<2;i++){
	ss1*=10;
	ss1+=s1[i]-'0';
}
	for(int i=0;i<2;i++){
	ss2*=10;
	ss2+=s2[i]-'0';
}
if(ss1==ss2){
	if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')){
		if(s1[2]+1==s2[2]||s1[2]-1==s2[2]){
			cout<<"1111";
		}else{
			cout<<"1110";
		}
	}else{
		cout<<"1100";
	}
}else{
	cout<<"1000";
}	
}else{
	cout<<"0000";
}

	return 0;
}
