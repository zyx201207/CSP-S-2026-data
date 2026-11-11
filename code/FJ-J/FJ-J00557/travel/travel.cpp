#include<bits/stdc++.h>
using namespace std;
int a,b;
string s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s1>>b>>s2;
	if(a!=b)
	{
		cout<<"0000";
		return 0;
	}
	cout<<'1';
	if(s1[0]!=s2[0]||s1[1]!=s2[1])
	{
		cout<<"000";
		return 0;
	}
	cout<<'1';
	if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')
	{
		cout<<'1';
		if(s1[2]=='A'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='A')
		{
			cout<<'0';
			return 0;
		}
		cout<<'1';
		return 0;
	}
	if(s1[2]>='E'&&s1[2]<='F'&&s2[2]>='E'&&s2[2]<='F')
	{
		cout<<"11";
		return 0;
	}
	cout<<"00";
}
