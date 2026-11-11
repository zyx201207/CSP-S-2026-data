#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s;
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	s[0] = s1[0];
	s[1] = s1[1];
	s[2] = s1[2];
	s[3] = s2[0];
	s[4] = s2[1];
	s[5] = s2[2];
	int a;
	if(c1 == c2){
		cout<<1;
		a = 1;
	}
	else{
		cout<<0;
		a = 0; 
	}
	if(a == 1){
		if(s[0]==s[3] && s[1]==s[4]){
			cout<<1;
			a = 1;
		}
		else{
			cout<<0;
			a = 0;
		}
	}
	else{
		cout<<0;
		a = 0;
	}
	if(a == 1){
		if((s[2]=='A' || s[2]=='B' || s[2]=='C') && (s[5]=='A' || s[5]=='B' || s[5]=='C')){
			cout<<1;
			a = 1;
		}
		else if((s[2]=='D' || s[2]=='F') && (s[5]=='D' || s[5]=='F')){
			cout<<1;
			a = 1;
		}
		else{
			cout<<0;
			a = 0;
		}
	}
	else{
		cout<<0;
		a = 0;
	}
	if(int(s[2]) > int(s[5])){
		if(a == 0){
			cout<<0;
		}
		else if(a==1 && int(s[2])-int(s[5])!=1){
			cout<<0;
		}
		else{
			cout<<1;
		}
	}
	else{
		if(a == 0){
			cout<<0;
		}
		else if(a==1 && int(s[5])-int(s[2])!=1){
			cout<<0;
		}
		else{
			cout<<1;
		}
	}
	return 0;
}
