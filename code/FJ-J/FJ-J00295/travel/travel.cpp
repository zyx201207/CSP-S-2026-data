#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
bool a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int x=(s1[0]-'0')*10+(s1[1]-'0'),y=(s2[0]-'0')*10+(s2[1]-'0');
	a=(c1==c2);
	b=((x==y)&&a);
	c=(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((s1[2]=='F'||s1[2]=='D')&&(s2[2]=='F'||s2[2]=='D')))&&b;
	d=((s1[2]=='B'&&(s2[2]=='C'||s2[2]=='A'))||(s1[2]=='A'&&s2[2]=='B')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='F'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='F'))&&c;
	cout<<a<<b<<c<<d;
	return 0;
} 
