#include<bits/stdc++.h>
using namespace std;

int main() 
{freopen("travel.in ","r",stdin);
freopen("travel.out ","w",stdout);
short a1,a2;
bool s=1;
cin>>a1;
char b[2][3];
cin>>b[0][0]>>b[0][1]>>b[0][2];
cin>>a2;
cin>>b[1][0]>>b[1][1]>>b[1][2];
if(a1==a2)
cout<<1;
else {
cout<<0;
s=0;}
if(s==1&&(b[0][0]==b[1][0]&&b[0][1]==b[1][1]))
cout<<1;
else {cout<<0;s=0;}
if(s==1&&(((b[0][2]=='A'||b[0][2]=='B'||b[0][2]=='C')&&(b[1][2]=='A'||b[1][2]=='B'||b[1][2]=='C'))||((b[0][2]=='D'||b[0][2]=='F')&&(b[1][2]=='D'||b[1][2]=='F'))))
cout<<1;
else
{
	cout<<0;
	s=0;
	}	
if(s==1&&((((b[0][2]+1==b[1][2])&&b[1][2]!='D')||((b[0][2]-1==b[1][2])&&b[0][2]!='D'))||((b[0][2]=='D'&&b[1][2]=='F')||(b[0][2]=='F'&&b[1][2]=='D'))))
cout<<1;
else cout<<0;
	return 0;
}
