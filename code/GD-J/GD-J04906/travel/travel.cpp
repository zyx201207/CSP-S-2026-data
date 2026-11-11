#include <bits/stdc++.h>

using namespace std;

string c1, s1, c2, s2;
string t1, t2;
char p1, p2;
int fg;
string ans;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> c1 >> s1 >> c2 >> s2;
	t1 = s1[0] + s1[1], t2 = s2[0] + s2[1];
	p1 = s1[2], p2 = s2[2];
	ans = "", fg = 1;
	if (c1 != c2) {
		fg = 0;
	}
	ans += (char)(fg + '0');
	if (t1 != t2) {
		fg = 0;
	}
	ans += (char)(fg + '0');
	if (((p1 <= 'C') && ('C' < p2)) || ((p2 <= 'C' && ('C' < p1)))) {
		fg = 0;
	}
	ans += (char)(fg + '0');
	if ((p1 == 'A' && p2 == 'C') || (p2 == 'A' && p1 == 'C')) {
		fg = 0;
	}
	ans += (char)(fg + '0');
	cout << ans << '\n';
	return 0;
}
