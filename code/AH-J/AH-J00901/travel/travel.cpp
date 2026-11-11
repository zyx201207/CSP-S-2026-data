#include<bits/stdc++.h>
using namespace std;
int main()
{
	//Trick||Treat!
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1,a2,c1,c2;
	string s1,s2;
	cin>>a1>>s1>>a2>>s2;
	if(a1==a2)
	{
		c1=(s1[0]-48)*10+s1[1]-48;
		c2=(s2[0]-48)*10+s2[1]-48;
		cout<<1;
		if(c1==c2)
		{
			int sum=0;
			cout<<1;
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
			{
				sum++;
			}
			if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
			{
				sum++;
			}
			if(sum==2||sum==0)
			{
				cout<<1;
				if((s1[2]=='A'&&s2[2]=='B') || (s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C')) || (s1[2]=='C'&&s2[2]=='B') || (s1[2]=='D'&&s2[2]=='F') || (s1[2]=='F'&&s2[2]=='D'))
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
}
