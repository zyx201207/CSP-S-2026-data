#include<bits/stdc++.h>
using namespace std;
int main(){
	string c1;string s1;string c2;string s2;
	getline(cin,c1);
	getline(cin,s1);
	getline(cin,c2);
	getline(cin,s1);
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}else{
		cout<<0;
	}
	if(s2[2]-1!=s1[2]||s2[2]+1==s1[2]){
		
		if(s1[2]=='C'&&s2[2]=='D'||s1[2]=='D'&&s2[2]=='C'){
			cout<<0;
			
		}else{
		cout<<1;
		}
	}else{
		cout<<0;
	}
	if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C'&&s2[2]=='A'||s2[2]=='b'||s2[2]=='c'
	)||(s1[2]=='D'||s1[2]=='F'&&s1[2]=='D'||s1[2]=='F')){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
