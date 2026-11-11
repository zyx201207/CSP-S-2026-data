#include<bits/stdc++.h>
using namespace std;
int C1,C2;
string s1;
string s2;
char a1,b1,c1,a2,b2,c2;
int num=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>C1;
	cin>>s1;
	a1=s1[0];
	b1=s1[1];
	c1=s1[2];
	cin>>C2;
	cin>>s2;
	a2=s2[0];
	b2=s2[1];
	c2=s2[2];
	if(C1!=C2)
	{
		cout<<"000";
		num=0;
	}
	else
	{
		num=1;
		if(b1+a1*10!=b2+a2*10)
		{
			cout<<"100";
		}
		else
		{
			if(b1+a1*10!=b2+a2*10)
			{
				cout<<100;
			}
			else
			{
					if(c2=='B'||c2=='C'&&c1=='A')
					{
						cout<<"111";
					}
					else	if(c2=='A'||c2=='C'&&c1=='B')
					{
						cout<<"111";
					}
					else	if(c2=='A'||c2=='B'&&c1=='C')
					{
						cout<<"111";
					}
					else	if(c2=='F'&&c1=='E')
					{
						cout<<"111";
					}
					else	if(c2=='E'&&c1=='F')
					{
						cout<<"111";
					}
					else
					{
						cout<<110;
					}
			}
		}
		
	}
		if(c1=='C'&&c2=='D')
		{
			cout<<0;
			return 0;
		 } 
		if(c2=='C'&&c1=='D')
		{
			cout<<0;
			return 0;
		 } 
		if(C1=C2&&a1*10+b1==a2*10+b1)
		{
			if(c1>c2)
			{
				if(c1-c2==1)
				{
					cout<<1;
					return 0;
				}
				else
				{
					cout<<0;
					return 0;
				}
			}
			else
			{
				if(c2-c1==1)
				{
					cout<<1;
					return 0;
				}
				else
				{
					cout<<0;
					return 0;
				}
			}
		}
		else
		{
			cout<<0;
			return 0;
		}
	return 0;
} 
