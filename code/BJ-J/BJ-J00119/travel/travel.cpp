#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define endl '\n'

signed main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int c1, c2;
	string s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2) cout << "0000";
	else
	{
		cout << 1;
		int n1 = (s1[0] - '0') * 10 + s1[1];
		int n2 = (s2[0] - '0') * 10 + s2[1];
		if (n1 != n2) cout << "000";
		else
		{
			cout << 1;
			if (s1[2] < 'D' && s2[2] < 'D')
			{
				if (abs((int )s1[2] - s2[2]) == 1) cout << 11;
				else cout << 10;
			}
			else if (s1[2] > 'C' && s2[2] > 'C') cout << 11;
			else cout << 00;
		}
	}
	
	return 0;
}