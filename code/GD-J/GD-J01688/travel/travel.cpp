#include <bits/stdc++.h>
using namespace std;
#define deb(n) cout << #n << " = " << n << '\n';
string c1, s1, c2, s2;

bool check(char c1, char c2) {
	if (c1 <= 'C' && c2 <= 'C') return true;
	if (c1 >= 'D' && c2 >= 'D') return true;
	return false;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) cout << 1;
	else cout << 0;
	if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1]) cout << 1;
	else cout << 0;
	if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && check(s1[2], s2[2])) cout << 1;
	else cout << 0;
	if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && check(s1[2], s2[2]) && abs(s1[2] - s2[2]) == 1) cout << 1;
	else cout << 0;
	return 0;
} 
