#include<bits/stdc++.h>
#define int long long

using namespace std;


string c1, c2, s1, s2;

signed main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2) cout << "0000"; else
	if(s1[0] != s2[0] || s1[1] != s2[1]) cout << "1000"; else
	if(s1[2] == 'C' && s2[2] == 'D') cout << "1100"; else
	if(s2[2] == 'C' && s1[2] == 'D') cout << "1100"; else
	if(min(s1[2], s2[2]) + 1 == max(s1[2], s2[2])) cout << "1111"; else
	cout << "1110";
	return 0; 
} // fc travel.out travel.ans 
