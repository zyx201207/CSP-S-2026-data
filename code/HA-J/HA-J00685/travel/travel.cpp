#include <bits/stdc++.h>
using namespace std;

int main () {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;

	bool same_c = (c1 == c2);
	bool same_line = (s1.substr(0, 2) == s2.substr(0, 2));
	bool same_side_C = (s1[2] <= 'C' && s2[2] <= 'C'), same_side_D = (s1[2] >= 'D' && s2[2] >= 'D');
	bool same_side = (same_side_C || same_side_D);
	char a = s1[2];
	char b = s2[2];
	if (a > b) swap(a, b);
	bool nearby = (same_c && same_line && same_side && ((a == 'A' && b == 'B') || (a == 'B' && b == 'C') || (a == 'D' && b == 'F')));

	cout << (same_c ? "1" : "0") << (same_c && same_line ? "1" : "0") << (same_c && same_line && same_side ? "1" : "0") << (nearby ? "1" : "0") << "\n";
	return 0;
}

