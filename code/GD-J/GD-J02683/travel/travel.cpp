#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, c2, s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2)
	{
		cout << 1;
		if (s1.substr(0, 2) == s2.substr(0, 2))
		{
			cout << 1;
			char a = s1[2];
			char b = s2[2];
			bool flag = 0;
			if ((a == 'A' || a == 'B' || a == 'C') && (b == 'A' || b == 'B' || b == 'C'))
				flag = 1;
			else if ((a == 'D' || a == 'F') && (b == 'D' || b == 'F'))
				flag = 1;
			if (flag)
			{
				cout << 1;
				int c = a - 'A', d = b - 'A';
				if (c == d + 1 || d == c + 1)
					cout << 1;
				else cout << "0";
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
