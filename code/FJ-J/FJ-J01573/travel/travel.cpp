#include <bits/stdc++.h>
using namespace std;
string c1, c3;
string c2, c4;
int x1, x2;
string s1, s2;
int s;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> c2 >> c3 >> c4;
	x1 = (c2[0] - '0') * 10 + (c2[1] - '0');
	x2 = (c4[0] - '0') * 10 + c4[1] - '0';
	s1 = c2[2];
	s2 = c4[2];
	//cout << x1 << x2 << s1 << s2;
	if(c1 == c3)
	{
		cout << 1;
		if(x1 == x2)
		{
			cout << 1;
			if(s1 == "D" && s2 == "F" || s1 == "F" && s2 == "D")
			{
				s = 1;
				cout << 1;
				if (s == 1 && abs(s1[0] - s2[0]) == 1)
					cout << 1;
				else 
					cout << 0;
			}
			else if(s1 == "D" || s2 == "D" || s1 == "F" || s2 == "F")
				cout << "00";
			else 
			{
				s = 1;
				cout << 1;
				if (s == 1 && abs(s1[0] - s2[0]) == 1)
					cout << 1;
				else 
					cout << 0;
			}
		}
		else 
			cout << "000";
	}
	else 
		cout << "0000";
	
}
