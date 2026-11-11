#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	bool c[5];
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		c[1]=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			c[2]=1;
			if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'||s1[2]=='D'&&s1[2]=='F'&&s2[2]=='D'&&s2[2]=='F')
			{
				c[3]=1;
				if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='C'&&s2[2]=='B'||s1[2]=='D'&&s2[2]=='F')
				{
					c[4]=1;
				}
				else c[4]=0;
			}
			else
			{
				c[3]=0;
				c[4]=0;
			}
		}
		else
		{
			c[2]=0;
			c[3]=0;
			c[4]=0;
		}
	}
	else 
	{
		c[1]=0;
		c[2]=0;
		c[3]=0;
		c[4]=0;
	}
	for(int i=1;i<=4;i++)cout<<c[i];
}
