#include<bits/stdc++.h>
using namespace std;
int a,b,a3,b3;
string a2,b2;
char a4,b4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a2>>b>>b2;
	a3=(a2[0]-'0')*10+a2[1]-'0';
	b3=(b2[0]-'0')*10+b2[1]-'0';
	a4=a2[2];
	b4=b2[2];
	if(a!=b)
	{
		cout<<"0000";
		return 0;
	}
	else
	{
		if(a3!=b3)
		{
			cout<<"1000";
			return 0;
		}
		else
		{
			
			if(a4!='D'&&a4!='F')
			{
				if(b4=='D'||b4=='F')
				{
					cout<<"1100";
					return 0;
				}
			}
			else
			{
				if(b4!='D'&&b4!='F')
				{
					cout<<"1100";
					return 0;
				}
			}
			if(a4=='A')
			{
				if(b4!='B')
				{
					cout<<"1110";
					return 0;
				}
			}
			else if(a4=='B')
			{
				if(b4!='A'&&b4!='C')
				{
					cout<<"1110";
					return 0;
				}
			}
			else if(a4=='C')
			{
				if(b4!='B')
				{
					cout<<"1110";
					return 0;
				}
			}
			else if(a4=='D')
			{
				if(b4!='F')
				{
					cout<<"1110";
					return 0;
				}
			}
			else
			{
				if(b4!='D')
				{
					cout<<"1110";
					return 0;
				}
			}
		}
	}
	cout<<"1111";
	return 0;
	
	
	
	
	
}
