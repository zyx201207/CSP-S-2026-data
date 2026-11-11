#include<iostream>
#include<cmath>
#include<string>
using namespace std;
string s1,s2,a1,a2;
char c[10];

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	c[1]='0';
	c[2]='0';
	c[3]='0';
	c[4]='0';
	cin>>s1>>s2>>a1>>a2;
	if((s1[0]==a1[0])&&(s1[1]==a1[1]))
	{
		c[1]='1';
		if(a2[0]==s2[0]&&a2[1]==s2[1])
		{
			c[2]='1';
			if((s2[2]<='C'&&a2[2]<='C')||(s2[2]>'D'&&a2[2]>'D'))
			{
				c[3]='1';
				if(s2[2]-a2[2]<2&&s2[2]-a2[2]>-2)
				{
					c[4]='1';
				}
			}
		}	
	}
	for(int i=1;i<=4;i++)
	{
		cout<<c[i];
	}
	return 0;
}
