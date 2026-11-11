#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int cr, cx;
	string sr, sx;
	cin >> cr >> sr >> cx >> sx;
	int pr = (sr[0]-'0')*10 + sr[1]-'0';
	int px = (sx[0]-'0')*10 + sx[1]-'0';
	int r = sr[2]-'A'+1, x = sx[2]-'A'+1;
	if(cr == cx) 
	{
		cout << 1;
		if(px == pr) 
		{
			cout << 1;
			if(r<=3&&x<=3 || r>=4&&x>=4)
			{
				cout << 1;
				if(r-x==1 || x-r==1) cout << 1;
				else if(r==4||r==6)
				{
					if(x==4||x==6) cout << 1;
				}
				else cout << 0;
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
