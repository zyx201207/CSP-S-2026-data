#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string cf, sf, cs, ss;
	cin >> cf >> sf >> cs >> ss;
	if (cf == cs)
	{
		cout << 1;
		if (sf[0] == ss[0] && sf[1] == ss[1])
		{
			cout << 1;
			if
			(
			(sf[2]>='A'&&sf[2]<='C'&&ss[2]>='A'&&ss[2]<='C') 
			|| (sf[2]>='D'&&sf[2]<='F'&&ss[2]>='D'&&ss[2]<='F')
			)
			{
					cout << 1;
				if (abs(sf[2]-ss[2]) == 1)
					cout << 1;
				else
				cout << 0;
			}
			else 
				cout << "00";
		}
		else
			cout << "000";
	}
	else
		cout << "0000";
	return 0;
}
