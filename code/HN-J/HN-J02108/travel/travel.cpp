#include<bits/stdc++.h>
using namespace std; 
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);	
int c1,c2,x=0,y=0,z=0;
string s1,s2;
cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		x=1;
	}else{
		cout<<0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&x==1){
		cout<<1;
		y=1;
	}else{
		cout<<0;
	}
	if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='D'&&s1[2]!='D'&&s2[2]!='D'&&x==1&&y==1||s1[2]>='D'&&s1[2]<='E'&&s2[2]>='D'&&s2[2]<='E'&&s1[2]!='D'&&s2[2]!='D'&&x==1&&y==1){
		cout<<1;
		z=1;
	}else{
		cout<<0;
	}
	if(x==1&&y==1&&z==1&&s1[2]+1==s2[2]&&s1[2]!='D'&&s2[2]!='D'||s1[2]-1==s2[2]&&s1[2]!='D'&&s2[2]!='D'&&x==1&&y==1&&z==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
