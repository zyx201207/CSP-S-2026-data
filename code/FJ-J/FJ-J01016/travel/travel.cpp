#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int rc,xc;
	string rw,xw;
	cin>>rc>>rw>>xc>>xw;
	if(rc==xc)
	{
		cout<<'1';
		if(rw[0]+rw[1]==xw[0]+xw[1])
		{
			cout<<'1';
			if(rw[2]==xw[2])
			{
				cout<<'1';
			}
			else if(rw[2]=='A')
			{
				if(xw[2]=='B')
				{
					cout<<"11";
				}
				else if(xw[2]=='C')
				{
					cout<<"10";
				}
				else
				{
					cout<<"00";
				}
			}
			else if(rw[2]=='B')
			{
				if(xw[2]=='B'||xw[2]=='C')
				{
					cout<<"11";
				}
				else
				{
				cout<<"00";
				}
			}
			else if(rw[2]=='C')
			{
				if(xw[2]=='B')
				{
					cout<<"11";
				}
				else if(xw[2]=='A')
				{
					cout<<"10";
				}
				else
				{
					cout<<"00";
				}
			}
			else if(rw[2]=='E')
			{
				if(xw[2]=='F')
				{
					cout<<"11";
				}
				else
				{
					cout<<"00";
				}
			}
			else if(rw[2]=='F')
			{
				if(xw[2]=='E')
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
	return 0;
}
