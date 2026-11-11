#include<bits/stdc++.h>
using namespace std;
string a1,b1,a2,b2;
bool b=true;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>a1>>b1>>a2>>b2;
	if(a1[0]==a2[0]&&a1[1]==a2[1])cout<<"1";
	else
	  {cout<<"0";
	  b=false;}
	if(b==true&&b1[0]==b2[0]&&b1[1]==b2[1])cout<<"1";
	else
	  {cout<<"0";
	  b=false;}
	if(b==true&&((b1[2]<='C'&&b2[2]<='C')||(b1[2]>='D'&&b2[2]>='D')))cout<<"1";
	else
	  {cout<<"0";
	  b=false;}
	if(b==true&&((b1[2]=='A'&&b2[2]=='B')||(b1[2]=='B'&&b2[2]=='A')||(b1[2]=='C'&&b2[2]=='B')||(b1[2]=='B'&&b2[2]=='C')||(b1[2]=='D'&&b2[2]=='F')||(b1[2]=='F'&&b2[2]=='D')))cout<<"1";
	else cout<<"0";
	return 0;
}