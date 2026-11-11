#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string a1,a2,b1,b2;
	a1=s1[0];
	a1+=s1[1];
	a2=s2[0];
	a2+=s2[1];
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
	{
		b1="down";
	}
	else
	{
		b1="up";
	}
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
	{
		b2="down";
	}
	else
	{
		b2="up";
	}
	//cout<<a1<<"\n"<<a2<<"\n"<<b1<<"\n"<<b2<<"\n";
	if(c1==c2)
	{
		cout<<1;
		if(a1==a2)
		{
			cout<<1;
			if(b1==b2)
			{
				cout<<1;
				if(b1=="up")
				{
					cout<<1;
				}
				else if(s1[2]=='A'&&s2[2]=='B')
				{
					cout<<1;
				}
				else if(s1[2]=='B'&&s2[2]=='C')
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
				cout<<"00";
			}
		}
		else
		{
			cout<<"000";
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}
