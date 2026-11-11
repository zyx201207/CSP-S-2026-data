#include <bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;
bool sameroom, sameline, sameop, bet;

bool Find(char c) {
	if (c == 'A' || c == 'B' || c == 'C') {
		return 1;
	}
	else {
		return 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	sameroom = (c1 == c2);
	sameline = (sameroom && s1[0] == s2[0] && s1[1] == s2[1]);
	sameop = (sameline && (Find(s1[2]) == Find(s2[2])));
	bet = ((abs((int)(s1[2]-s2[2])) == 1 || (s1[2] == 'F' && s2[2] == 'D') || (s1[2] == 'D' && s2[2] == 'F') )&& sameop);
	cout << sameroom << sameline << sameop << bet << '\n';
	return 0;
}
