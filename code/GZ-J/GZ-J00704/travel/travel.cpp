//GZ-J00704 遵义市新蒲中学 谢俊星
#include<bits/stdc++.h>
using namespace std;
bool XXX(char a,char b,char x,char y){
	if(((a==x)&&(b==y))||((a==y)&&(b==x))){
		return 1;
	}
	return 0;
}
bool BBBB(char a,char b){
	if((XXX(a,b,'A','B')||XXX(a,b,'A','C'))||XXX(a,b,'B','C')){
		return 1;
	}
	if(XXX(a,b,'D','F')){
		return 1;
	}
	return 0;
}
bool BBBB1(char a,char b){
	if(XXX(a,b,'A','B')||XXX(a,b,'B','C')){
		return 1;
	}
	if(XXX(a,b,'D','F')){
		return 1;
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1_a,s1_b,s2_a,s2_b;
	cin>>s1_a>>s1_b>>s2_a>>s2_b;
	if(s1_a!=s2_a){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if((s1_b[0]!=s2_b[0])||(s1_b[1]!=s2_b[1])){
		cout<<"000";
		return 0;
	}
	cout<<"1";
	if(!(BBBB(s1_b[2],s2_b[2]))){
		cout<<"00";
		return 0;
	}
	cout<<"1";
	if(!(BBBB1(s1_b[2],s2_b[2]))){
		cout<<"0";
		return 0;
	}
	cout<<"1";
	return 0;
}

