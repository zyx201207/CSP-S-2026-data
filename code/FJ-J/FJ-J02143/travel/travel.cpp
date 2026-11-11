#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
bool check3(){
	return c1==c2;
}
bool check(){
	return (s1[0]-'0')*10+(s1[1]-'0')==(s2[0]-'0')*10+(s2[1]-'0');
}
bool check1(){
	if(s1[2]=='A'){
		if(s2[2]=='A'||s2[2]=='B'||s2[3]=='C') return true;
		else return false;
	}else if(s1[2]=='B'){
		if(s2[2]=='A'||s2[2]=='B'||s2[3]=='C') return true;
		else return false;
	}
	else if(s1[2]=='C'){
		if(s2[2]=='A'||s2[2]=='B'||s2[3]=='C') return true;
		else return false;
	}
	else if(s1[2]=='D'){
		if(s2[2]=='D'||s2[2]=='E') return true;
		else return false;
	}
	else{
		if(s2[2]=='D'||s2[2]=='E') return true;
		else return false;
	}
}
bool check2(){
	if(abs((s1[2]-'A')-(s2[2]-'A'))==1) return true;
	else return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(check3()) cout<<1;
	else cout<<0;
	if(check3()&&check()) cout<<1;
	else cout<<0;
	if(check3()&&check()&&check1()) cout<<1;
	else cout<<0;
	if(check3()&&check()&&check1()&&check2()) cout<<1;
	else cout<<0;
	return 0;
}
