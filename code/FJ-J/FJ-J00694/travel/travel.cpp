#include<bits/stdc++.h>
using namespace std;
string c1,c2;
char s1[5],s2[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	bool b=1;
	if(c1==c2)cout<<1;
	else {b=0;cout<<0;}
	if(b==1&&s1[1]==s2[1]&&s1[0]==s2[0])cout<<1;
	else {b=0;cout<<0;}
	if(b==1&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')))cout<<1;
	else {b=0;cout<<0;}
	if(b==1&&((s1[2]+1==s2[2]||s2[2]+1==s1[2])||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')))cout<<1;
	else cout<<0;
	return 0;
} 
