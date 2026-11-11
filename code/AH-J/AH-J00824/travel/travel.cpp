#include<bits/stdc++.h>
using namespace std;
string a,a2,b,b2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a2>>b>>b2;
	if(a==b)
	{
		cout<<1;
		if(a2[0]==b2[0]&&a2[1]==b2[1])
		{
			cout<<1;
			if(a2[2]=='A')
			{
				if(b2[2]=='B')
				{
					cout<<"11";
				}
				else if(b2[2]=='C')
				{
					cout<<"10";
				}
				else
				{
					cout<<"00";
				}
				
			}
			else if(a2[2]=='B')
			{
				if(b2[2]=='A')
				{
					cout<<"11";
				}
				else if(b2[2]=='C')
				{
					cout<<"11";
				}
				else
				{
					cout<<"00";
				}
				
			}
			else if(a2[2]=='C')
			{
				if(b2[2]=='A')
				{
					cout<<"10";
				}
				else if(b2[2]=='B')
				{
					cout<<"11";
				}
				else
				{
					cout<<"00";
				}
				
			}
			else if(a2[2]=='D')
			{
				if(b2[2]=='F')
				{
					cout<<"11";
				}
				else
				{
					cout<<"00";
				}
				
			}
			else if(a2[2]=='F')
			{
				if(b2[2]=='D')
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
		cout<<"0000";
	}
}
