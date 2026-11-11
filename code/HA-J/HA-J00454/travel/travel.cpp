#include <bits/stdc++.h>
using namespace std;
int rt,xt;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string rs,xs;
	cin >> rt>>rs>>xt>>xs;
	if (rt == xt)
	{
		cout << 1;
		{
			if (rs[0]==xs[0] && rs[1]==xs[1])
			{
				cout<<1;
				if ((rs[2]=='A' || rs[2]=='B' || rs[2]=='C')&&(xs[2]=='A' || xs[2]=='B' || xs[2]=='C'))
				{
					cout << 1;
					if (rs[2]-xs[2]==1 || rs[2]-xs[2]==-1)
					{
						cout << 1;
					}
					else
					{
						cout <<0;
					}
				}
				else if((rs[2]=='D' || rs[2]=='F')&&(xs[2]=='D' || xs[2]=='F'))
				{
					cout << 11;
				}
				else
				{
					cout <<"00";
				}
			}
			else
			{
				cout << "000";
			}
		}
	}
	else
	{
		cout << "0000";
	}
	return 0;
}
