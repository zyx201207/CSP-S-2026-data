#include <bits/stdc++.h>
using namespace std;
string ca, sa, cb, sb;
int main () {
	ios::sync_with_stdio (0);
	cin.tie (0);
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	cin >> ca >> sa >> cb >> sb;
	if (ca != cb) cout << "0000";
	else if (sa.substr (0, 2) != sb.substr (0, 2)) cout << "1000";
	else if (((sa[2] == 'A' || sa[2] == 'B' || sa[2] == 'C') && (sb[2] == 'D' || sb[2] == 'F')) || ((sb[2] == 'A' || sb[2] == 'B' || sb[2] == 'C') && (sa[2] == 'D' || sa[2] == 'F'))) cout << "1100";
	else if ((sa[2] == 'A' && sb[2] == 'C') || (sa[2] == 'C' && sb[2] == 'A')) cout << "1110";
	else cout << "1111";
	return 0;
} 
