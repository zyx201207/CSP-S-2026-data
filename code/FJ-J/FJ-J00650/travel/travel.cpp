#include<bits/stdc++.h>
using namespace std;

int c1, c2;
string s1, s2;
int s11, s22;

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
	s11 = (s1[0] - '0') * 10 + (s1[1] - '0');
	s22 = (s2[0] - '0') * 10 + (s2[1] - '0');
	
	if (c1 == c2) cout << 1;
	else cout << 0;
	
	if (c1 == c2 && s11 == s22) cout << 1;
	else cout << 0;
	
	if (s1[2] > s2[2]) swap(s1[2], s2[2]);
	
	if (c1 == c2 && s11 == s22 && ((s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'A' && s2[2] == 'C') || (s1[2] == 'B' && s2[2] == 'C'))) cout << 1;
	else cout << 0;
	
	if (c1 == c2 && s11 == s22 && ((s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'B' && s2[2] == 'C'))) cout << 1;
	else cout << 0;
	
	return 0;
}