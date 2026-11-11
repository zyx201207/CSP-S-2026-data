#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string Xc,Xz,Rc,Rz;
	cin>>Xc>>Xz>>Rc>>Rz;
	if(Xc == Rc)
	{
		cout<<"1";
		if(Xz[0] == Rz[0] && Xz[1] == Rz[1])
		{
			cout<<"1";
			if(Xz[2] == 'A' || Xz[2] == 'B' || Xz[2] == 'C')
			{
				if(Rz[2] == 'A' || Rz[2] == 'C' || Rz[2] == 'B')
				{
					cout<<"1";
					if(Xz[2] == Rz[2]+1 || Rz[2] == Xz[2]+1)
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
				if(Rz[2] == 'D' || Rz[2] == 'E')
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
