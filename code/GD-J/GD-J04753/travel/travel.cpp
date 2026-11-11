#include <bits/stdc++.h>

#define int long long

using namespace std;
string s1, c1, s2, c2, ans;

signed main() {

    freopen ("travel.in", "r", stdin);
    freopen ("travel.out", "w", stdout);
    cin >> s1 >> c1 >> s2 >> c2;	
    if (s1 == s2) ans += '1';
    else ans += '0';
    if (ans[0] == '1' && c1[0] == c2[0] && c1[1] == c2[1]) ans += '1';
    else ans += '0';
    if (ans[1] == '1' && c1[2] >= 'A' && c1[2] <= 'C' && c2[2] >= 'A' && c2[2] <= 'C') ans += '1';
    else if (ans[1] == '1' && c1[2] >= 'D' && c1[2] <= 'F' && c2[2] >= 'D' && c2[2] <= 'F') ans += '1';
	else ans += '0';
	if (ans[2] == '1' && abs(c1[2] - c2[2]) == 1) ans += '1';
	else ans += '0';
	cout << ans; 
	return 0;
} 
