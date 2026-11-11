#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int a1, a2, b1, b2;
	char c1, c2;
	cin >> a1 >> a2 >> c1 >> b1 >> b2 >> c2;
	if (a1 == b1) 
	{
		cout << "1";
		if (a2 == b2) 
		{
			cout << "1";
			if (((c1 == 'A' || c1 == 'B' || c1 == 'C') && (c2 == 'D' || c2 == 'F')) || ((c2 == 'A' || c2 == 'B' || c2 == 'C') && (c1 == 'D' || c1 == 'F')))	cout << "00";
			else 
			{
				cout << "1";
				if (abs((int)c1 - (int)c2) == 1) cout << "1";
				else cout << "0";
			}
		}
		else cout << "000";	
	}
	else cout << "0000";
	return 0;
}
