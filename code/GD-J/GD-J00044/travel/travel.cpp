#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5; 
int n, m, k, sum, cnt;
string c1, s1, c2, s2;
int get(string s) {
	if (s[2] == 'A' || s[2] == 'B' || s[2] == 'C')
		return 1;
	else
		return 2;
}
bool check(string s, string s2) {
	if ((s[2] == 'A' && s2[2] == 'B') || (s[2] == 'B' && s2[2] == 'C') || (s[2] == 'D' && s2[2] == 'F'))
		return 1;
	if ((s2[2] == 'A' && s[2] == 'B') || (s2[2] == 'B' && s[2] == 'C') || (s2[2] == 'D' && s[2] == 'F'))
		return 1;
	return 0;
}
signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); 
	int i, j, x, y, z, t;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2)
		cout << 1;
	else
		cout << 0;
	if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1])
		cout << 1;
	else
		cout << 0;
	if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && get(s1) == get(s2))
		cout << 1;
	else
		cout << 0;
	if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && get(s1) == get(s2) && check(s1, s2))
		cout << 1;
	else
		cout << 0;
	return 0;
}
