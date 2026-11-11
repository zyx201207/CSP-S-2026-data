#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e3 + 10;

string r_1, r_2, x_1, x_2;

bool yes(char q, char p) {
	if (q == 'A' && (p == 'B' || p == 'C')) return true;
	else if (q == 'B' && (p == 'A' || p == 'C')) return true;
	else if (q == 'C' && (p == 'A' || p == 'B')) return true;
	else if ((q == 'D' && p == 'F') || (q == 'F' && p == 'D')) return true;
	else return false;
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ll f = 0;
	cin >> r_1 >> r_2 >> x_1 >> x_2;
	
	if (r_1 == x_1) f = 1, cout << "1";
	else cout << "0";
	
	ll r = r_2[0], x = x_2[0], w = r_2[1], s = x_2[1];
	if (r == x && w == s && f == 1) cout << "1";
	else cout << "0";
	
	char a = r_2[2], b = x_2[2];
	ll m = ll(a), n = ll(b);
	if (r == x && w == s && f == 1 && yes(a, b)) cout << "1";
	else cout << "0";
	
	
	if (r == x && w == s && f == 1 && (m == n + 1 || m == n - 1) && yes(a, b)) cout << "1";
	else cout << "0";
	return 0;
}
