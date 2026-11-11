#include<bits/stdc++.h>
using namespace std;
bool check(char a,char b){
	if(((a>='A'&&a<='C')&&(b>='A'&&b<='C'))||((a=='D'||a=='F')&&(b=='D'||b=='F')))return true;
	return false;
}
bool Next(char a,char b){
	if(abs(a-b)==1)return true;
	else if((a=='D'&&b=='F')||(a=='F'&&b=='D'))return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else cout<<0;
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1])cout<<1;
	else cout<<0;
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&check(s1[2],s2[2]))cout<<1;
	else cout<<0;
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&check(s1[2],s2[2])&&Next(s1[2],s2[2]))cout<<1;
	else cout<<0;
	return 0;
}
