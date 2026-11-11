#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a1, a2;
	string s1, s2;
	cin >> a1 >> s1 >> a2 >> s2;
	if(a1 == a2)
	{
		cout << "1";
		if(s1[0] == s2[0] && s1[1] == s2[1])
		{
			cout << "1";
			char ch1 = s1[2], ch2 = s2[2];
			if(((ch1 == 'D' || ch1 == 'F') && (ch2 == 'D' || ch2 == 'F'))) cout << "11";
			else if((ch1 == 'A' || ch1 == 'B' || ch1 == 'C') && (ch2 == 'A' || ch2 == 'B' || ch2 == 'C'))
			{
				cout << "1";
				if(abs(ch1 - ch2) == 1) cout << "1";
				else cout << "0";
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
} 
