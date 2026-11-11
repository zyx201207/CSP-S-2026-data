#include <bits/stdc++.h>
using namespace std;

int mp[128];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	
	bool g = true;
	
	cout << int(c1 == c2);
	if(c1 != c2) g = false;
	
	string t1 = s1.substr(0, 2), t2 = s2.substr(0, 2);
	cout << (g && t1 == t2);
	if(t1 != t2) g = false;
	
	char ch1 = s1[2], ch2 = s2[2];
	mp['A'] = 0, mp['B'] = 1, mp['C'] = 2, mp['D'] = 10, mp['F'] = 11;
	
	if(g && (abs(mp[ch1] - mp[ch2]) <= 2)) cout << 1;
	else cout << 0, g = false;
	
	if(g && (abs(mp[ch1] - mp[ch2]) <= 1)) cout << 1;
	else cout << 0;
	
	return 0;
}
