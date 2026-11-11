//GZ-J00566  七星关东辰实验学校  袁若雪

#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("trave.in","r",stdin);
	freopen("trave.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int z=0,y=0;
	for(int i=0;i<2;i++){
		if(c1[i]==c2[i]&&c1[i+1]==c2[i+1]){
			z=1;
		} 
	}
	if(z=1)cout<<1;
	else{
		cout<<0;
	}
	for(int i=0;i<2;i++){
    	if(s1[i]==s2[i]&&s1[i+1]==s2[i+1]){
			y=1;
		} 
	}
	if(y=1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if((s1[2]=='A'&&s2[2]=='B'||s2[2]=='C')||(s1[2]=='B'&&s2[2]=='C'||s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B'||s2[2]=='A')||(s1[2]=='D'&&s2[2]=='E')||(s1[2]=='E'&&s2[2]=='D')){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='E')||(s1[2]=='E'&&s2[2]=='D')){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
} 
