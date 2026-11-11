#include <bits/stdc++.h>
using namespace std;
int c1, s11, c2, s21;
string s12, s22;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c1 >> s11 >> s12 >> c2 >> s21 >> s22;
	if(c1 != c2) cout << "0000";
	else
	{
		if(s11 != s21) cout << 1000;
		else
		{
			if(((s12 == "A" || s12 == "B" || s12 == "C") && (s22 == "A" || s22 == "B" || s22 == "C"))
			|| ((s12 == "D" || s12 == "F") && (s22 == "D" || s22 == "F")))
			{
				if((s12 == "A" && s22 == "B") || (s12 == "B" && s22 == "A") || (s12 == "B" && s22 == "C") || (s12 == "C" && s22 == "B") || (s12 == "D" && s22 == "F") || (s12 == "F" && s22 == "D"))
				{
					cout << 1111;
				}
				else cout << 1110;
			}
			else cout << 1100;
		}
	}
	return 0;
}
