#include <bits/stdc++.h>
using namespace std;
int seat(string s)
{
	if (s[0] == '0') return int(s[1] - '0');
	else return int((s[0] - '0') * 10 + (s[1] - '0'));
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin >> a >> b >> c >> d;
	char s1 = b[2],s2 = d[2];
	int l1 = seat(b),l2 = seat(d),c1 = seat(a),c2 = seat(c);
	if (c1 == c2)
	{
		cout << 1;
		if (l1 == l2)
		{
			cout << 1;
			if (s1 == 'A' && s2 == 'B' || s1 == 'B' && s2 == 'C' || s1 == 'A' && s2 == 'C' || s1 == 'D' && s2 == 'F')
			{
				cout << 1;
				if (s1 == 'A' && s2 == 'B' || s1 == 'B' && s2 == 'C' || s1 == 'D' && s2 == 'F')
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
