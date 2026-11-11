#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string n,m,p,q;
	cin>>n>>p>>m>>q;
	if(n==m)
	{
		if(p[0]==q[0] && p[1]==q[1])
		{
			if(p[2]=='A')
			{
				if(q[2]=='B')
				{
					cout<<"1111";
				}
				else if(q[2]=='C')
				{
					cout<<"1110";
				}
				else 
				{
					cout<"1100";
				}
			}
			else if(p[2]=='B')
			{
				if(q[2]=='A' || q[2]=='C')
				{
					cout<<"1111";
				}
				else 
				{
					cout<<"1100";
				}
			}
			else if(p[2]=='C')
			{
				if(q[2]=='B')
				{
					cout<<"1111";
				}
				else if(q[2]=='A')
				{
					cout<<"1110";
				}
				else 
				{
					cout<<"1100";
				}
			}
			else if(p[2]=='D')
			{
				if(q[2]=='F')
				{
					cout<<"1111";
				}
				else
				{
					cout<<"1100";
				}
			}
			else if(p[2]=='F')
			{
				if(q[2]=='D')
				{
					cout<<"1111";
				}
				else
				{
					cout<<"1100";
				}
			}
		}
		else 
		{
			cout<<"1000";
		}
		
	}
	else
	{
		cout<<"0000";
	}
}
