#include<bits/stdc++.h>
using namespace std;
string s1, s2, x1, x2;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> x1 >> s1 >> x2 >> s2;
	if(x1 != x2) cout << "0000";
	else
	{
		cout << 1;
		int a1 = (s1[0] - '0') * 10 + (s1[1] - '0'), a2 = (s2[0] - '0') * 10 + (s2[1] - '0');
		char b1 = s1[2], b2 = s2[2];
		if(a1 == a2)
		{
			cout << 1;
			if((b1 <= 'C' && b2 <= 'C') || (b1 > 'C' && b2 > 'C'))
			{
				cout << 1;
				int t = int(b1 - b2);
				if(abs(t) == 1) cout << 1;
				else cout << 0;
			}
			else cout << "00";
		}
		else cout << "000";
	}
	return 0;
}
