#include<bits/stdc++.h>
using namespace std;
char a,b,q,w,e,r,o,p,k,l;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>o>>p>>q>>w>>a>>k>>l>>e>>r>>b;
	if(o==k&&l==p)
	{
		cout<<"1";
		if(q==e&&w==r)
		{
			cout<<"1";
			if(a=='F')
			{
				if(b=='D')
				{
					cout<<"11";
				}
				else
				{
					cout<<"00";
				}
			}
			else if(a=='D')
			{
				if(b=='F')
				{
					cout<<"11";
				}
				else
				{
					cout<<"00";
				}
			}
			else if(a=='A')
			{
				if(b=='B')
				{
					cout<<"11";
				}
				else if(b=='C')
				{
					cout<<"10";
				}
				else
				{
					cout<<"00";
				}
			}
			else if(a=='B')
			{
				if(b=='D'||b=='F')
				{
					cout<<"00";
				}
				else
				{
					cout<<"11";
				}
			}
			else
			{
				if(b=='B')
				{
					cout<<"11";
				}
				else if(b=='A')
				{
					cout<<"10";
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
	return 0;
}
