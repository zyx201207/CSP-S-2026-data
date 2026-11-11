#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;
int main(){
	int c1,c2;
	char s1[4]={};
	char s2[4]={};
	cin>>c1;
	for(int i=0;i<3;i++){
		cin>>s1[i];
	}
	cin>>c2;
	for(int i=0;i<3;i++){
		cin>>s2[i];	
	}
	if(c1!=c2)cout<<"0000";
	else if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<"11";
		if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
			cout<<"1";
			if(s1[2]==s2[2]+1||s1[2]==s2[2]-1)cout<<"1";
			else cout<<"0";
		}
		else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
			cout<<"11";
		}
		else cout<<"00";
	}
	else cout<<"1000";
	return 0;
}
