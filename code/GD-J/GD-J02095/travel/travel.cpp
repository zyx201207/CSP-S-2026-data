#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s;
	string t;
	string s1;
	string t1;
	cin>>s>>s1>>t>>t1;
	if(s==t)
	{
		cout<<"1"; 
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(s1[0]=='0'&&t1[0]=='0')
	{
		if(s1[1]==t1[1])
		{
			cout<<"1";
			if(s1[2]=='A')
			{
				if(t1[2]=='B'||t1[2]=='C')
				{
					cout<<"1";
					if(t1[2]=='B')
					{
						cout<<"1";
					}
				}
				else
				{
					cout<<"00";
				}
			}
			else if(s1[2]=='B')
			{
				if(t1[2]=='A'||t1[2]=='C')
				{
					cout<<"11";
				}
				else
				{
					cout<<"00";
				}
			}
			else if(s1[2]=='C')
			{
				if(t1[2]=='B'||t1[2]=='A')
				{
					cout<<"1";
					if(t1[2]=='B')
					{
						cout<<"1";
					}
					else
					{
						cout<<"0";
					}
				}
				else
				{
					cout<<"00";
				}
			}
			else if(s1[2]=='D')
			{
				if(t1[2]=='F')
				{
					cout<<"11";
				}
				else
				{
					cout<<"00";
				}
			}
			else
			{
				if(t1[2]=='D')
				{
					cout<<"11"; 
				}
				else
				{
					cout<<"00";
				}
			}
		}
		else
		{
			cout<<"000";
		}
	}
	else
	{
		cout<<"000";
	}
	return 0;
}
