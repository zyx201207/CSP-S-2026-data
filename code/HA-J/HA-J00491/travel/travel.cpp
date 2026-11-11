#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string rc,rs,xc,xs;
	cin >> rc >> rs >> xc >> xs;
	if(rc==xc)
	{
		cout << 1;
		if(rs[0]==xs[0] && rs[1]==xs[1]) 
		{
			cout << 1;
			if((rs[2]>='A' && rs[2]<='C') && (xs[2]>='A' && xs[2]<='C') || (rs[2]=='D' || rs[2]=='F') && (xs[2]=='D' && xs[2]=='F'))
			{
				cout << 1;
				if(rs[2]-xs[2]==1 || rs[2]-xs[2]==-1)
				{
					cout << 1;
				}
				else
				{
					cout << 0;
				}
			}
			else
			{
				cout << 0 << 0;
			}
		}
		else
		{
			cout << 0 << 0 << 0;
		}	
	}
	else
	{
		cout << 0 << 0 << 0 << 0;
	}
	return 0;
 } 
