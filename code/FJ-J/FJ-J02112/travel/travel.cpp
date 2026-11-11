#include<bits/stdc++.h>
using namespace std;
bool check1(char s,char t)
{
	if((s=='A'||s=='B'||s=='C')&&(t=='A'||t=='B'||t=='C'))
	{
		return 1;
	}
	if((s=='D'||s=='F')&&(t=='D'||t=='F'))
	{
		return 1;
	}
	return 0;
}
bool check2(char s,char t)
{
	if(s=='A'&&t=='B'||s=='B'&&t=='C'||s=='D'&&t=='F')
	{
		return 1;
	}
	if(t=='A'&&s=='B'||t=='B'&&s=='C'||t=='D'&&s=='F')
	{
		return 1;
	}
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if(c1==c2&&s1.substr(0,2)==s2.substr(0,2))
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if(c1==c2&&s1.substr(0,2)==s2.substr(0,2)&&check1(s1[2],s2[2]))
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if(c1==c2&&s1.substr(0,2)==s2.substr(0,2)&&check1(s1[2],s2[2])&&check2(s1[2],s2[2]))
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	return 0;
}
