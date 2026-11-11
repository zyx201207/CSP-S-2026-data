#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<map>
using namespace std;
int x1,x2;
string s1,s2,ans;
bool f(char a,char b){
	if(a>='A'&&a<='C'&&b>='A'&&b<='C'&&s1!=s2)return true;
	else if((a=='F'&&b=='D')||(a=='D'&&b=='F'))return true;
	return false;
}
int main(){

	freopen("travel5.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x1>>s1>>x2>>s2;
	if(x1==x2)cout<<1;
	else {cout<<"0000";return 0;}
	if(s1[0]==s2[0]&&s1[1]==s2[1])cout<<1;
	else {cout<<"000";return 0;}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		char a=s1[2],b=s2[2];
		
		if(f(a,b))cout<<1;
		else {cout<<"00";return 0;}
		
		if(a>b)swap(a,b);
		if(a+1==b||(a=='D'&&b=='F'))cout<<1;
		else cout<<0;
	}
	return 0;
}
