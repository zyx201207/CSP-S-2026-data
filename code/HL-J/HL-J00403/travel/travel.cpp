#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s;
	getline(cin,s);
	if(s[1]==s[8]){
		cout<<'1';
	}else{
		cout<<"0000";
		return 0;
	}
	if(s[3]==s[10]&&s[4]==s[11]){
		cout<<'1';
	}else{
		cout<<"000";
		return 0;
	}
	if(s[5]=='D'&&s[12]=='F'||s[5]=='F'&&s[12]=='D'){
		cout<<"11";
	}else if(s[5]=='A'&&s[12]=='B'||s[5]=='B'&&s[12]=='A'){
		cout<<"11";
	}else if(s[5]=='B'&&s[12]=='C'||s[5]=='C'&&s[12]=='B'){
		cout<<"11";
	}else if(s[5]=='A'&&s[12]=='C'||s[5]=='C'&&s[12]=='A'){
		cout<<"10";
	}else{
		cout<<"00";
	}
	return 0;
}
