#include<bits/stdc++.h>
using namespace std;
string s,s1,s2,s3;
int a[1000],b,c,d,e,f,g;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>s1>>s2>>s3;
	b=10*(s[0]-'0')+s[1]-'0';
	c=10*(s2[0]-'0')+s2[1]-'0';
	d=10*(s1[0]-'0')+s1[1]-'0';
	e=10*(s3[0]-'0')+s3[1]-'0';
	f=s1[2]-'A'+1;
	g=s3[2]-'A'+1;
	if(b==c)
	{
		cout<<1;
		if(d==e)
		{
			cout<<1;
			if(f<=3&&g<=3)
			{
				cout<<1;
				if(f-g==1||g-f==1)
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
			}
			else if(f>3&&g>3)
			{
				cout<<1;
				if(f-g==1||g-f==1)
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
			}
		}
		else
		{
			cout<<0<<0<<0;
		}
	}
	else 
	{
		cout<<0<<0<<0<<0;
	}
	return 0;
}
