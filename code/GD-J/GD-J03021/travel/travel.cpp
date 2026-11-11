#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool f=1;
	//1
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<0;
		f=0;
	}
	//2
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&f){
		cout<<1;
	}
	else{
		cout<<0;
		f=0;
	}
	//3
	if((s1[2]=='F'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='F')&&f){
		cout<<1;
	}
	else if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')&&f){
		cout<<1;
	}
	else if((s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')&&f){
		cout<<1;
	}
	else if((s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A')&&f){
		cout<<1; 
	}
	else{
		cout<<0;
		f=0;
	}
	//4
	if((s1[2]=='F'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='F')&&f){
		cout<<1;
	}
	else if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')&&f){
		cout<<1;
	}
	else if((s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')&&f){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
} 
