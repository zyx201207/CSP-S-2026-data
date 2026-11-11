#include<bits/stdc++.h>
using namespace std;
#define _for(i,x,y,z) for(int i=x;i<=y;i+=z)
string c,s;
string c1,s1;
bool check(char a,char b){return ((a=='A'&&b=='B')||(a=='A'&&b=='C')||(a=='B'&&b=='C')||(a=='B'&&b=='A')
||(a=='D'&&b=='F')||(a=='C'&&b=='A')||(a=='C'&&b=='B')||(a=='F'&&b=='D'));}
bool check1(char a,char b){return ((a=='A'&&b=='B')||(a=='B'&&b=='C')||(a=='B'&&b=='A')
||(a=='D'&&b=='F')||(a=='C'&&b=='B')||(a=='F'&&b=='D'));}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>c1>>s1;
	if(c!=c1)cout<<"0000";
	else if(s[1]!=s1[1])cout<<"1000";
	else if(!check(s[2],s1[2]))cout<<"1100";
	else if(!check1(s[2],s1[2]))cout<<"1110";
	else cout<<"1111";
}
