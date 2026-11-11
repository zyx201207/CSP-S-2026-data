#include <bits/stdc++.h>
#define ll long long
#define N 100005
#define rep(x, y, z) for (int x = y; x <= z; x++)
#define inf 1e18
using namespace std;
string s; 
int x, y, z, X, Y, Z;
int main() {
	freopen("travel.in", "r", stdin), freopen("travel.out", "w", stdout);
	cin >> s; x = (s[0] - 48) * 10 + (s[1] - 48);
	cin >> s; y = (s[0] - 48) * 10 + (s[1] - 48);
	z = s[2] - 'A';
	cin >> s; X = (s[0] - 48) * 10 + (s[1] - 48);
	cin >> s; Y = (s[0] - 48) * 10 + (s[1] - 48);
	Z = s[2] - 'A';
	if (x != X) cout << "0000";
	else if (y != Y) cout << "1000";
	else if ((z <= 2) != (Z <= 2)) cout << "1100";
	else if (abs(z - Z) != 1) cout << "1110";
	else cout << "1111";
	return 0;
}
