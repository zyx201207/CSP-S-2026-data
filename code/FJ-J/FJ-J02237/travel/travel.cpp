#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char z1,z2;
	string s1,s2,x1,x2;
	int c1,c2,p1,p2;
	cin>>x1>>s1>>x2>>s2;
	c1=x1[0]*10+x1[1];
	c2=x2[0]*10+x2[1];
	p1=s1[0]*10+s1[1];
	p2=s2[0]*10+s2[1];
	z1=s1[2];
	z2=s2[2];
	if(c1==c2)
	{
		cout<<"1";
		if(p1==p2)
		{
			cout<<"1";
			if((z1=='A'&&z2=='B')||(z1=='B'&&z2=='A')||(z1=='B'&&z2=='C')||(z1=='C'&&z2=='B')||(z1=='D'&&z2=='E')||(z1=='E'&&z2=='D'))
			{
				cout<<"11";
				return 0;
			}
			else 
			{
				if((z1=='A'&&z2=='C')||(z1=='C'&&z2=='A'))
				{cout<<"10";
				return 0;
				}
				else
					{cout<<"00";
					return 0;
					}
			}
		}
		else
		{
			cout<<"000";
			return 0; 
		}
	}
	else 
	{
		cout<<"0000";
		return 0;
	}
	return 0;
}