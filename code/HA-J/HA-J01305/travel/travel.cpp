#include <bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;

bool check (int a, int b) {
	if (a <= 2 && b <= 2) return true;
	if (a >= 3 && b >= 3) return true;
	return false;
}

bool ncheck (int a, int b) {
	if (check (a, b) && abs (a - b) == 1) return true;
	else return false;
}

signed main ()
{	
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);

	ios::sync_with_stdio (false);
	cin.tie (nullptr);
	
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << 1;
		if (s1.substr (0, 2) == s2.substr (0, 2)) {
			cout << 1;
			char a = s1[2], b = s2[2];
			cout << (check (a - 'A', b - 'A') ? 1 : 0);
			cout << (ncheck (a - 'A', b - 'A') ? 1 : 0);
		}
		else cout << 0 << 0 << 0;
	}else cout << 0 << 0 << 0 << 0;
	
	return 0;
}
