#include<bits/stdc++.h>

using namespace std;


int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string r,rh,x,xh;
	cin >> r >> rh >> x >> xh;
	if (r == x)
	{
		cout << "1";
		if (rh[0] == xh[0] && rh[1] == xh[1])
		{
			cout << "1";
			if (!((rh[2] >= 'D' && xh[2] <= 'C') || (rh[2] <= 'C' && xh[2] >= 'D')))
			{
				cout << "1";
				if (abs(rh[2] - xh[2]) == 1) cout << "1";
				else cout << "0";
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
