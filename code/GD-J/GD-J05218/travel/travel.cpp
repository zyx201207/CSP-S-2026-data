#include<bits/stdc++.h>
using namespace std;
string c,c1,s,s1;

int main(){
	cin>>c>>s>>c1>>s1;
	if(c!=c1){
		cout<<"0000";
		return 0;
	}
	if(s[0]!=s1[0] || s[1]!=s1[1]){
		cout<<"1000";
		return 0;
	}
	if((s[2]>='D' && s1[2]<='C') || (s[2]<='C' && s1[2]>='D')){
		cout<<"1100";
		return 0;
	}
	if(s[2]!=s1[2]+1 && s1[2]!=s[2]+1){
		cout<<"1110";
		return 0;
	}else{
		cout<<"1111";
	}
	return 0;
}