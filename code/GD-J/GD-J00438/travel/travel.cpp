#include <bits/stdc++.h>
using namespace std;
int main (){
	freopen("travel.in","r","stdin");
	freopen("travel.out","w","stdout");
	bool a=1,b=1;
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(s1[2]=='A' || s1[2]=='B' || s1[2]=='C'){
		if(s2[2]=='A' || s2[2]=='B' || s2[2]=='C'){
			bool a=1;
		}
		else{
			bool a=0;
		}
	}
	if(s1[2]=='D' || s1[2]=='F'){
		if(s2[2]=='D' || s2[2]=='F'){
			bool a=1;
		}
		else{
			bool a=0;
		}
	}
	if(s1[2]=='C'){
		if(s1[2]-1==s2[2]){
			b=1;
		}
		else{
			b=0;
		}
	}
	if(s1[2]=='D'){
		if(s1[2]+1==s2[2]){
			b=1;
		}
		else{
			b=0;
		}
	}
	if(s2[2]=='C'){
		if(s2[2]-1==s1[2]){
			b=1;
		}
		else{
			b=0;
		}
	}
	if(s2[2]=='D'){
		if(s2[2]+1==s1[2]){
			b=1;
		}
		else{
			b=0;
		}
	}
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(s1[1]==s2[1] && c1==c2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(a==1 && s1[1]==s2[1] && c1==c2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(s1[2]+1==s1[2] || s1[2]-1==s2[2] && b==1 && a==1 && s1[1]==s2[1] && c1==c2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
} 
