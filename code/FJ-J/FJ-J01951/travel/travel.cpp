#include<bits/stdc++.h>
using namespace std;
string c_1,s_1,c_2,s_2,s="";
int main(){
    cin>>c_1>>s_1>>c_2>>s_2;
    if(c_1==c_2){
    	s[0]='1';
	}else{
		cout<<"0000";
		return 0;
	}
	if(s_1[1]==s_2[1]){
		s[1]='1';
	}else{
		cout<<"1000";
		return 0;
	}
	if(((s_1[2]=='F'||s_1[2]=='D')&&(s_2[2]=='F'||s_2[2]=='D'))||((s_1[2]=='A'||s_1[2]=='B'||s_1[2]=='C')&&(s_2[2]=='A'||s_2[2]=='B'||s_2[2]=='C'))){
		s[2]='1';
	}else{
		cout<<"1100";
		return 0;
	}
	if(s_1[2]=='A'&&s_2[2]=='B'){
		cout<<"1111";
	}else if(s_1[2]=='B'&&s_2[2]=='A'){
		cout<<"1111";
	}else if(s_1[2]=='C'&&s_2[2]=='B'){
		cout<<"1111";
	}else if(s_1[2]=='B'&&s_2[2]=='C'){
		cout<<"1111";
	}else if(s_1[2]=='F'&&s_2[2]=='D'){
		cout<<"1111";
	}else if(s_1[2]=='D'&&s_2[2]=='F'){
		cout<<"1111";
	}else{
		cout<<"1110";
	}
	return 0;
}
