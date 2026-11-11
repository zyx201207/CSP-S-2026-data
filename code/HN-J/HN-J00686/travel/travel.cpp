#include<iostream>
using namespace std;
string rc,xc,rs,xs;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc>>rs>>xc>>xs;
	string n="ABCDF";
	if(rc==xc)
	{
		cout<<"1";
		if(rs[0]==xs[0] && rs[1]==xs[1])
		{
			cout<<"1";
			if((rs[2]==n[3] || rs[2]==n[4])&&(xs[2]==n[3] || xs[2]==n[4]))
			{
				cout<<"11";
			}
			else if((rs[2]==n[0] || rs[2]==n[1] || rs[2]==n[2])&&(xs[2]==n[0] || xs[2]==n[1] || xs[2]==n[2]))
			{
				cout<<"1";
				if(rs[2]==xs[2]-1 || rs[2]-1==xs[2])
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
