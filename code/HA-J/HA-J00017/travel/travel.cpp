#include<bits/stdc++.h>
using namespace std;
#define ll long long
signed main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	if (s1 != s3) {
		cout << "0000";
		return 0;
	}
	cout << "1";
	if (s2.substr(0, 2) != s4.substr(0, 2)) {
		cout << "000";
		return 0;
	}
	cout << "1";
	char c1 = s2[2], c2 = s4[2];
	if (c1 > c2) {
		swap(c1, c2);
	}
	map<char, int> mp;
	mp['A'] = mp['B'] = mp['C'] = 1;
	mp['D'] = mp['F'] = 2;
	if (mp[c1] != mp[c2]) {
		cout << "00";
		return 0;
	}
	cout << "1";
	if ((mp[c1] == 1 && c2 - c1 == 1) || (mp[c2] == 2 && c2 == 'F' && c1 == 'D')) {
		cout << "1";
	} else {
		cout << "0";
	}
	return 0;
}