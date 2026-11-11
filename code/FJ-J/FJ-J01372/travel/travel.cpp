#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int getNum(string s){
	int retVal=(s[0]-'0')*10+(s[1]-'0');
	return retVal;
}
bool fun1(string s1,string s2){
	char a=s1[2],b=s2[2];
	if(
		(a=='A'&&b=='B') ||
		(a=='B'&&b=='A') ||
		(a=='B'&&b=='C') ||
		(a=='C'&&b=='B') ||
		(a=='A'&&b=='C') ||
		(a=='C'&&b=='A') ||
		(a=='D'&&b=='F') ||
		(a=='F'&&b=='D')
	){
		return true;
	}else{
		return false;
	}
}
bool fun2(string s1,string s2){
	char a=s1[2],b=s2[2];
	if(
		(a=='A'&&b=='B') ||
		(a=='B'&&b=='A') ||
		(a=='B'&&b=='C') ||
		(a=='C'&&b=='B') ||
		(a=='D'&&b=='F') ||
		(a=='F'&&b=='D')
	){
		return true;
	}else{
		return false;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int c1,c2;string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000"<<endl;
		return 0;
	}
	cout<<"1";
	if(getNum(s1)==getNum(s2)){
		cout<<"1";
	}else{
		cout<<"000"<<endl;
		return 0;
	}
	if(fun1(s1,s2)){
		cout<<"1";
	}else{
		cout<<"00"<<endl;
		return 0;
	}
	if(fun2(s1,s2)){
		cout<<"1";
	}else{
		cout<<"0"<<endl;
		return 0;
	}
	cout<<endl;
	
	
	return 0;
}
