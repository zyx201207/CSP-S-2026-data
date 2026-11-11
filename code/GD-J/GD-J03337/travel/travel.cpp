#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int check(char ch) {
	if (ch >= 'A' && ch <= 'C') return 1;
	else return 2; 
}
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2) cout << "0000" << '\n';
	else {
		if (s1.substr(0, 2) != s2.substr(0, 2)) cout << "1000" << '\n';
		else {
			int l1 = check(s1[2]), l2 = check(s2[2]);
			if (l1 != l2) cout << "1100" << '\n';
			else {
				if (s1[2] > s2[2]) swap(s1[2], s2[2]);
				if (s1[2] + 1 == s2[2]) cout << "1111" << '\n';
				else cout << "1110" << '\n';				 
			}
		}
	}
	return 0;
} 
