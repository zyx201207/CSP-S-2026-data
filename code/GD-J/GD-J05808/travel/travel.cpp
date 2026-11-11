#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string zr = "",zx = "",cr = "",cx = "";
	cin>>cr>>zr>>cx>>zx;
	string s = "",s1 = "";
	for(int i = 0;i<2;i++)
	{
		s += zr[i];
		s1 += zx[i];
	}
	if(cr == cx)
	{
		cout<<1;
		if(s == s1)
		{
			cout<<1;
			if((zr[2] >= 'A' && zr[2] <= 'C') && (zx[2] >= 'A' && zx[2] <= 'C'))
			{
				cout<<1;
				if(zr[2] == 'A' && zx[2] == 'B')
				{
					cout<<1;
				}
				else if(zx[2] == 'A' && zr[2] == 'B')
				{
					cout<<1;
				}
				else if(zr[2] == 'C' && zx[2] == 'B')
				{
					cout<<1;
				}
				else if(zr[2] == 'B' && zx[2] == 'C')
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
			}
			else if((zr[2] == 'D' || zr[2] == 'F') && (zx[2] == 'D' || zx[2] == 'F'))
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
		else
		{
			cout<<0;
			cout<<0;
			cout<<0;
		}
	}
	else
	{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
	}
	return 0;
}
