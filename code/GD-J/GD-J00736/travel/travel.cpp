#include<bits/stdc++.h>
using namespace std;
string x,y,r,c;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> x >> y >> r >> c;
	if(x == r)
	{
		cout << 1;
		if((y[0] - '0') * 10 + (y[1] - '0') == (c[0] - '0') * 10 + (c[1] - '0'))
		{
			cout << 1;
			char c1 = y[2],c2 = c[2];
			if((c1 >= 'A' && c1 <= 'C' && c2 >= 'A' && c2 <= 'C') || (c1 >= 'D' && c1 <= 'F' && c2 >= 'D' && c2 <= 'F'))
			{
				cout << 1;
				if((c1 == 'A' && c2 == 'B') || (c1 == 'B' && c2 == 'A') || (c1 == 'C' && c2 == 'B') || (c1 == 'B' && c2 == 'C') || (c1 == 'D' && c2 == 'F') || (c1 == 'F' && c2 == 'D'))
				{
					cout << 1;
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
