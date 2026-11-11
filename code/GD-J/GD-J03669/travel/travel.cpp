#include <bits/stdc++.h>
using namespace std;
char a[10], b[10];
int main()
{
//	freopen("travel.in", "r", stdin);
//	freopen("travel.out", "w", stdout);
	for (int i = 1; i <= 2; i++) cin >> a[i];
	for (int i = 3; i <= 4; i++) cin >> a[i];
	cin >> a[5];
	a[5] -= 'A';
	for (int i = 1; i <= 2; i++) cin >> b[i];
	for (int i = 3; i <= 4; i++) cin >> b[i];
	cin >> b[5];
	b[5] -= 'A';
	if (a[1] == b[1] && a[2] == b[2]) 
	{
		cout << "1";
		if (a[3] == b[3] && a[4] == b[4]) 
		{
			cout << "1";
			if (a[5] < 3 && b[5] < 3) 
			{
				cout << "1";
				if (abs(a[5] - b[5]) == 1) cout << "1\n";
				else cout << "0\n";
			}
			else if (a[5] >= 3 && b[5] >= 3) 
			{
				cout << "1";
				if (abs(a[5] - b[5]) == 1) cout << "1\n";
				else cout << "0\n";
			}
			else cout << "00\n";
		} 
		else cout << "000";
	} 
	
	else cout << "0000";
	
	
	
	return 0;
} 
