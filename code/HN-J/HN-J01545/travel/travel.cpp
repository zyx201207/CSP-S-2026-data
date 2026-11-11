#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define file(s)	freopen(#s".in", "r", stdin), freopen(#s".out", "w", stdout)
const int N = 2e5 + 10;
signed main() {
	file(travel);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2)	cout << 1;
	else	cout << 0;
	string t1 = s1.substr(0, 2);
	string t2 = s2.substr(0, 2);
	if (c1 == c2 && t1 == t2)	cout << 1;
	else	cout << 0;
	map<char, int> mp1, mp2;
	mp1['F'] = mp1['D'] = 1;
	mp1['A'] = mp1['B'] = mp1['C'] = 2;
	if (c1 == c2 && t1 == t2 && mp1[s1[2]] == mp1[s2[2]])	cout << 1;
	else	cout << 0;
	mp2['A'] = 1, mp2['B'] = 2, mp2['C'] = 3, mp2['D'] = 4, mp2['F'] = 5;
	if (c1 == c2 && t1 == t2 && mp1[s1[2]] == mp1[s2[2]] && abs(mp2[s1[2]] - mp2[s2[2]]) == 1)	cout << 1;
	else	cout << 0;
	return 0;
}
