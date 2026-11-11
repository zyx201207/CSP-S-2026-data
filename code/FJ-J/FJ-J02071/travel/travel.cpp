#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2) cout << 0 << 0 << 0 << 0;
	else if(s1[0] != s2[0] || s1[1] != s2[1]) cout << 1000;
	else if(!(('A' <= s1[2] && s1[2] <= 'C' && 'A' <= s2[2] && s2[2] <= 'C') || ('D' <= s1[2] && s1[2] <= 'E' && 'D' <= s2[2] && s2[2] <= 'E'))) cout << 1100;
	else if(abs(s1[2]-s2[2]) != 1) cout << 1110;
	else cout << 1111;
	return 0;
}
