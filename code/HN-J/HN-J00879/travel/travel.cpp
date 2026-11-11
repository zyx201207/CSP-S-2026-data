#include<bits/stdc++.h>
using namespace std;
int v1,v2;
string s1,s2;
int n1,n2,q1,q2,q3,q4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>v1;
	for(int i=0;i<=2;i++)
	{
		cin>>s1[i];
	}
	cin>>v2;
	for(int i=0;i<=2;i++)
	{
		cin>>s2[i];
	}
	if(s1[2]=='A')
	{
		n1=1;
	}
	if(s1[2]=='B')
	{
		n1=2;
	}
	if(s1[2]=='C')
	{
		n1=3;
	}
	if(s1[2]=='D')
	{
		n1=4;
	}


	if(s2[2]=='A')
	{
		n2=1;
	}
	if(s2[2]=='B')
	{
		n2=2;
	}
	if(s2[2]=='C')
	{
		n2=3;
	}
	if(s2[2]=='D')
	{
		n2=4;
	}
	if(v1==v2)
	{
		q1=1;
		if(s1[0]*10+s1[1]==s2[0]*10+s2[1])
		{
			q2=1;
			if(n1<=3&&n2<=3||n1>3&&n2>3)
			{
				q3=1;	
				if(n2==n1+1||n2==n1-1)
				{
					q4=1;	
					cout<<"1111";
				}		
				else
				{
					cout<<"1110";

				}
			}		
			else
			{
				cout<<"1100";

			}
		}		
		else
		{
			cout<<"1000";
		}
	}		
	else
	{
		cout<<"0000";
	}
	return 0;
} 
