#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a, b;
string stra, strb;
int s[200];
int main () {
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	ios::sync_with_stdio (false), cin.tie (0), cout.tie (0);
	s['D'] = s['F'] = 2;
	s['A'] = s['B'] = s['C'] = 1;
	cin >> a >> stra >> b >> strb;
	cout << (a == b);
	cout << (stra.substr (0, 2) == strb.substr (0, 2) && a == b);
	cout << ((s[(int)stra[2]] == s[(int)strb[2]]) && stra.substr (0, 2) == strb.substr (0, 2) && a == b);
	cout << ((s[(int)stra[2]] == s[(int)strb[2]] && (abs (stra[2] - strb[2]) == 1 || s[(int)stra[2]] == 2)) && stra.substr (0, 2) == strb.substr (0, 2) && a == b);
	return 0;
}
