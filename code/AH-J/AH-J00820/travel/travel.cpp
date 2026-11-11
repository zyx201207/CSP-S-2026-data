#include<bits/stdc++.h> 
using namespace std;
string s[3],s1[3];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s[1]>>s[2]>>s1[1]>>s1[2];
	if(s[1][1]==s1[1][1]){
		cout<<1;
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(s[2][1]==s1[2][1]){
		cout<<1;
	}
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if((s[2][2]<='C'&&s1[2][2]<='C')||(s[2][2]>'C'&&s1[2][2]>'C')){
		cout<<1;
	}
	else{
		cout<<0<<0;
		return 0;
	}
	if(int(s[2][2]-s1[2][2])==1||int(s[2][2]-s1[2][2])==-1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}

