#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1,c2,s2;
	char ch1,ch2;
	cin >> c1 >> s1 >> ch1 >> c2 >> s2 >> ch2;
	if (ch1 == 'F') ch1 = 'E';
	if (ch2 == 'F') ch2 = 'E';
	if (c1 == c2) cout << 1;
	else cout << 0;
	if (c1 == c2 and s1 == s2) cout << 1;
	else cout << 0;
	if (c1 == c2 and s1 == s2 and ((ch1 < 'D' and ch2 < 'D') or (ch1 >'C' and ch2 > 'C'))) cout << 1;
	else cout << 0;
	if (c1 == c2 and s1 == s2 and ((ch1 < 'D' and ch2 < 'D') or (ch1 >'C' and ch2 > 'C')) and (min(ch1,ch2) + 1 == max(ch1,ch2)))
		cout << 1;
	else cout << 0;
	return 0;
} 
