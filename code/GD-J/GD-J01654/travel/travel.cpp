#include<iostream>

using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2)
	{
		cout<<1;
		int ns1,ns2;
		ns1=s1[1]-'0';
		ns2=s2[1]-'0';
		if(s1[0]) ns1+=(s1[0]-'0')*10;
		if(s2[0]) ns2+=(s2[0]-'0')*10;
		
		if(ns1==ns2)
		{
			cout<<1;
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
			{
				
				if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
				{
					cout<<1;
					if(s1[2]==char(s2[2]-1)||s1[2]==(s2[2]+1)||s1[2]==s2[2])
					{
						cout<<1;
					}
					else
					{
						cout<<0;
					}
				}
				else
				{
					cout<<0<<0;
					return 0;
				}
			}
			else 
			{
				if(s2[2]=='D'||s1[2]=='E')
				{
					cout<<1;
					if(s1[2]==s2[2]-1||s1[2]==s2[2]+1||s1[2]==s2[2])
					{
						cout<<1;
					}
					else
					{
						cout<<0;
					}
				}
				else
				{
					cout<<0<<0;
					return 0;
				}
			}
		}
		else
		{
			cout<<0<<0<<0;
			return 0;
		}
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
} 
