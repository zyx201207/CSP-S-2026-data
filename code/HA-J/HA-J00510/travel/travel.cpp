#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
//string pin(string s){
//	string l=(char)(s[0])+(char)(s[1]);
//	return l;
//}
bool fun(char a,char b){
//	if(s[2]>='A'&&s[2]<='C'){
//		if(l[2]==s[2])return false;
//		if(l[2]>='A'&&l[2]<='C')return true;
//	}
//	if(s[2]=='D'||s[2]=='F'){
//		if(l[2]==s[2])return false;
//		if(l[2]=='D'||s[2]=='F')return true;
//	}
	if(a==b)return false;
	if((a>='A'&&a<='C'&&b>='A'&&b<='C')||((a=='D'||a=='F')&&(b=='D'&&b=='F'))){
		return true;
	}else{
		return false;
	}
}
bool fun2(char a,char b){
	return ((a=='A'&&b=='B')||(a=='B'&&b=='C')||(a=='D'&&b=='F'));
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	
	
	if(c1!="01"&&c1!="16")cout<<"1";
	else cout<<"0";
	
	
	if(s1.substr(0,2)==s2.substr(0,2)){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	
	
	if(fun(s1[2],s2[2]))cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	
	
	if(fun2(s1[2],s2[2])){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}