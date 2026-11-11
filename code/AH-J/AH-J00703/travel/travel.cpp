#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int a=s1[0];
	int b=s1[1];
	int c=s2[0];
	int d=s2[1];
	if(c1==c2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	
	
	if(a==c && b==d)
	{
		cout<<"1";
	}
	else
	{
		cout<<"000";
		return 0;
	}
	
	
	if((s1[2]=='C' && s2[2]=='D') || (s1[2]=='C' && s2[2]=='F'))
	{
		cout<<"0";
	}
	else if((s1[2]=='D' && s2[2]=='C') || (s1[2]=='F' && s2[2]=='C'))
	{
		cout<<"0";
	}
	else if(char(s1[2])>char(s2[2]))
	{
		if(char(s1[2])-char(s2[2])<=2)
		{
			cout<<"1";
		}
		else
		{
			cout<<"00";
			return 0;
		}
	}
	else if(char(s1[2])<char(s2[2]))
	{
		if(char(s2[2])-char(s1[2])<=2)
		{
			cout<<"1";
		}
		else
		{
			cout<<"00";
			return 0;
		}
	}
	
	
	if(s1[2]=='A' && s2[2]=='B')
	{
		cout<<"1";
	}
	else if(s1[2]=='B' && s2[2]=='A')
	{
		cout<<"1";
	}
	else if(s1[2]=='B' && s2[2]=='C')
	{
		cout<<"1";
	}
	else if(s1[2]=='D' && s2[2]=='F')
	{
		cout<<"1";
	}
	else if(s1[2]=='F' && s2[2]=='D')
	{
		cout<<"1";
	}
	return 0;
}
