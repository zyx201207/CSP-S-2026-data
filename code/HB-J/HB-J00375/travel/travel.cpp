#include <bits/stdc++.h>
#define int long long
using namespace std;
string s1, s2, s3, s4;
bool a[15];
signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s1 >> s2 >> s3 >> s4;
	if (s1 == s3) a[1] = 1;
	if (s2[0] == s4[0] && s2[1] == s4[1] && a[1]) a[2] = 1;
	if (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') {
		if (s4[2] == 'A' || s4[2] == 'B' || s4[2] == 'C') {
			if (a[1] && a[2]) a[3] = 1;
		}
	} 
	if (s2[2] == 'D' || s2[2] == 'F') {
		if (s4[2] == 'D' || s4[2] == 'F') {
			if (a[1] && a[2]) a[3] = 1;
		}
	}
	if (s2[2] == 'A' && s4[2] == 'B') a[4] = 1;
	if (s2[2] == 'B' && (s4[2] == 'A' || s4[2] == 'C')) a[4] = 1;
	if (s2[2] == 'C' && s4[2] == 'B') a[4] = 1;
	if (s2[2] == 'D' && s4[2] == 'F') a[4] = 1;
	if (s2[2] == 'F' && s4[2] == 'D') a[4] = 1;
	if (a[1] == 0 || a[2] == 0 || a[3] == 0) a[4] = 0;
	cout << a[1] << a[2] << a[3] << a[4] << "\n";
	return 0;
}
