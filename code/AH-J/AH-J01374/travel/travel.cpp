#include<bits/stdc++.h>
using namespace std;
string rc,rs,xc,xs,rz,rw,xz,xw;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc>>rs>>xc>>xs;
	rz+=rs[0];
	rz+=rs[1];
	rw=rs[2];
	xz+=xs[0];
	xz+=xs[1];
	xw=xs[2];
	if(rc==xc)
	{
		cout<<"1";
		if(rz==xz)
		{
			cout<<1;
			if(rw=="A")
			{
				if(xw=="B")
				{
					cout<<"11";
					return 0;
				}
				if(xw=="C")
				{
					cout<<"10";
					return 0;
				}
				if(xw=="D")
				{
					cout<<"00";
					return 0;
				}
				if(xw=="F")
				{
					cout<<"00";
					return 0;
				}
			}
			else
			if(rw=="B")
			{
				if(xw=="A")
				{
					cout<<"11";
					return 0;
				}
				if(xw=="C")
				{
					cout<<"11";
					return 0;
				}
				if(xw=="D")
				{
					cout<<"00";
					return 0;
				}
				if(xw=="F")
				{
					cout<<"00";
					return 0;
				}
			}
			else
			if(rw=="C")
			{
				if(xw=="A")
				{
					cout<<"10";
					return 0;
				}
				if(xw=="B")
				{
					cout<<"11";
					return 0;
				}
				if(xw=="D")
				{
					cout<<"00";
					return 0;
				}
				if(xw=="F")
				{
					cout<<"00";
					return 0;
				}
			}
			else
			if(rw=="D")
			{
				if(xw=="A")
				{
					cout<<"00";
					return 0;
				}
				if(xw=="B")
				{
					cout<<"00";
					return 0;
				}
				if(xw=="C")
				{
					cout<<"00";
					return 0;
				}
				if(xw=="F")
				{
					cout<<"11";
					return 0;
				}
			}
			else
			if(rw=="F")
			{
				if(xw=="A")
				{
					cout<<"00";
					return 0;
				}
				if(xw=="B")
				{
					cout<<"00";
					return 0;
				}
				if(xw=="C")
				{
					cout<<"00";
					return 0;
				}
				if(xw=="D")
				{
					cout<<"11";
					return 0;
				}
			}
		}
		else
		{
			cout<<"000";
			return 0;
		}
	}
	else
		cout<<"0000";
	return 0;
}
