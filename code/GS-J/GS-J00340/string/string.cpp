#include<bits/stdc++.h>
using namespase std;
int main()
{
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
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
	if(s1[1]==s2[1]&&s1[2]==s2[2])
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if((s1[3]=='A'||s1[3]=='B'||s1[3]=='C')&&(s2[3]=='A'||s2[3]=='B'||s2[3]=='C'))
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if(s1[3]=='A'&&s2[3]=='B')
	{
		cout<<"1";
	}
	else if(s1[3]=='B'&&s2[3]=='C')
	{
		cout<<"1";
	}
	else if(s1[3]=='D'&&s2[3]=='F')
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	return 0;
}
