//GZ-J00509 взО§КЦ КывужабЇ 
#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
char num1,num2,zm1,zm2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1])
	{
		cout<<1;
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
		}
	if(s1[0]==s2[0]&&s1[1]==s2[1])
	{
		cout<<1;
	}
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if(s1[2]<='C'&&s2[2]<='C')
	{
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(s1[2]>'C'&&s2[2]>'C')
	{
		cout<<1<<1;
		return 0; 
	}
	if(s1[2]=='C'&&s2[2]=='B')
	{
		cout<<1;
		return 0;
	}
	if(s1[2]=='B'&&s2[2]=='C')
	{
		cout<<1;
		return 0;
	}
	if(s1[2]=='B'&&s2[2]=='A')
	{
		cout<<1;
		return 0;
	}
	if(s1[2]=='A'&&s2[2]=='B')
	{
		cout<<1;
		return 0;
	}
	cout<<0;
	return 0;
}
