#include<bits/stdc++.h>
using namespace std;
int c1,c2,f=1;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else {cout<<0;f=0;}
	int a,b;
	a=(s1[1]-'0')+(s1[0]-'0')*10;
	b=(s2[1]-'0')+(s2[0]-'0')*10;
	if(a==b&&f)cout<<1;
	else {cout<<0;f=0;}
	if(s1[2]>'C'&&s2[2]>'C'&&f)cout<<1;
	else if(s1[2]<='C'&&s2[2]<='C'&&f)cout<<1;
	else {cout<<0;f=0;}
	if((s1[2]+1==s2[2]||s1[2]-1==s2[2])&&f)cout<<1;
	else cout<<0; 
	return 0;
} 
