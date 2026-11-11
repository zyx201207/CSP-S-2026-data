#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int c1,c2;
string s1,s2;
int k1=0,k2=0;
int n1,n2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	n1=int(s1[0])*10+int(s1[1]);
	n2=int(s2[0])*10+int(s2[1]); 
	if (c1==c2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0000";
		return 0; 
	}
	if (n1==n2)
	{
		cout<<"1";
		if (s1[2]>='A'&&s1[2]<='C')
		{
			k1=0; 
		}
		else
		{
			k1=1;
		}
		if (s2[2]>='A'&&s2[2]<='C')
		{
			k2=0; 
		}
		else
		{
			k2=1;
		}
		if (k1==k2)
		{
			cout<<"1";
		}
		else
		{
			cout<<"0";
		}
	}
	else
	{
		cout<<"00";
	}
    if (c1==c2)
	{
		if (k1==k2)
		{
			if (n1+1==n2||n1-1==n2)
			{
				if (s1[2]==s2[2])
				{
					cout<<"1";
					return 0;
				}
			}
			else if (n1==n2)
			{
				if(s1[2]==s2[2]-1||s1[2]==s2[2]+1)
				{
					cout<<"1";
					return 0;
				}
			}	
		}
	}
	cout<<"0"; 
	return 0;
 } 
