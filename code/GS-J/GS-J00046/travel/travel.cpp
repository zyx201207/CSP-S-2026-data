#include<bits/stdc++.h>
using namespace std;

string a1, a2, b1, b2;
char a3, b3;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a1 >> a2 >> b1 >> b2;
	if (a1 != b1) cout << "0000";
	else
	{
		cout << 1;
		if(a2[0] != b2[0] || a2[1] != b2[1]) cout << "000";
		else
		{
			cout << 1;
			a3 = a2[2], b3 = b2[2];
			if ((a3 == 'A' && b3 == 'B') || (a3 == 'B' && b3 == 'C') || (b3 == 'A' && a3 == 'B') || (b3 == 'B' && a3 == 'C') || (a3 == 'D' && b3 == 'F') || (b3 == 'D' && a3 == 'F'))
			{
				cout << "11";
			}
			else if ((a3 == 'A' && b3 == 'C') || (b3 == 'A' && a3 == 'C'))
			{	
				cout << "10";
			}
			else
				cout << "00";
		}
	}
	return 0;
}
