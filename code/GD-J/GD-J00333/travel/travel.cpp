#include <bits/stdc++.h>

using namespace std;
using ll = long long;
bool f1(string s1, string s2) {
	return s1.substr(0, 2) == s2.substr(0, 2);
}
bool f2(string s1, string s2) {
	int a = (s1[2] <= 'C'), b = (s2[2] <= 'C');
	return a == b;
}
bool f3(string s1, string s2) {
	char a = s1[2], b = s2[2];
	if (a > b) swap(a, b);
	return (a == 'D' && b == 'F') || b == (char)(a + 1);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	cout << (c1 == c2 ? 1 : 0);
	cout << (c1 == c2 && f1(s1, s2) ? 1 : 0);
	cout << (c1 == c2 && f1(s1, s2) && f2(s1, s2) ? 1 : 0);
	cout << (c1 == c2 && f1(s1, s2) && f2(s1, s2) && f3(s1, s2) ? 1 : 0) << "\n";
	return 0;
} 
