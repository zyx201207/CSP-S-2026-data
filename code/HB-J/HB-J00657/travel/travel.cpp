#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cc,ss,c,s;
	cin>>c>>s>>cc>>ss;
	if(cc!=c)
	{
		cout<<"0000";
	}
	else
	{
		cout<<1;
		int l=max(s.size(),ss.size());
		for(int  i=0;i<l;i++)
		{
			if(s[i]!=ss[i])
			{
				if(s[i]>='0'&&s[i]<='9'&&s[i]>='0'&&s[i]<='9')
				{
					cout<<0;
					cout<<0;
					cout<<0;
					return 0;
				}
				
				
			}
		}
		cout<<1;
		int x=s.size()-1,y=ss.size()-1;
		if(s[x]=='A'||s[x]=='B'||s[x]=='C')
		{
			if(ss[y]=='A'||ss[y]=='B'||ss[y]=='C')
			{
				cout<<1;
				if(ss[y]=='A'&&s[x]=='B')
				{
					cout<<1;
				}
				else if(ss[y]=='B'&&s[x]=='A')
				{
					cout<<1;
				}
				else if(ss[y]=='B'&&s[x]=='C')
				{
					cout<<1;
				}
				else if(ss[y]=='C'&&s[x]=='B')
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
				cout<<0;
				cout<<0;
			}
		}
		else
		{
			if(ss[y]=='D'||ss[y]=='F')
			{
				cout<<1;
				cout<<1;
			}
			else
			{
				cout<<0;
				cout<<0;
			}
		}
	}
	return 0;
}
