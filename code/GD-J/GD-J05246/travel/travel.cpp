#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,flag=0;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	char h1=s1[2];
	char h2=s2[2];
	if(c1==c2){
		cout<<1;
		flag++;
	}
	else{
		cout<<0;
	}
	
	if(s1[0]==s2[0] && s1[1]==s2[1] &&flag==1){
		cout<<1;
		flag++;
	}
	else{
		cout<<0;
	}
	if((int('A')<=h1&&h1<=int('C'))&&(int('A')<=h2&&h2<=int('C')) && flag==2){
		cout<<1;
		flag++;
	}
	else if(h1>'c'&&h2>'c'&&flag==2){
		cout<<1;
		flag++;
	}
	else{
		cout<<0;
	}
	if((h1-h2==1||h1-h2==-1) &&flag==3){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0; 
} 
