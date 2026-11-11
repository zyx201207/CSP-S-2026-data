#include <bits/stdc++.h>
using namespace std;
string a,b,s,c;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> s >> b >> c;
	if (a == b)
	{
		cout << 1;
		if (s[0] == c[0] && s[1] == c[1])
		{
			cout << 1;
			if (s[2] <= 'C' && c[2] <= 'C' || s[2] >= 'D' && c[2] >= 'D')
			{
				cout << 1;
				if (s[2] >= 'D' && c[2] >= 'D' || !((s[2] == 'A' && c[2] == 'C') || (c[2] == 'A' && s[2] == 'C'))) cout << 1;
				else cout << 0;
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
