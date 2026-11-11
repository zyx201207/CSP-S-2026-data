#include <bits/stdc++.h>
using namespace std;

string s1, s2;
long long c1, c2;
bool a[35];

void is () {
	string sit1, sit2;
	sit1 = s1[2], sit2 = s2[2];
	if (c1 == c2) {
		a[1] = true;
	} if ((s1[0] == s2[0]) && (s1[1] == s2[1])) {
		a[2] = true;
	} if ((sit1 == 'A' || sit1 == 'B' || sit1 == 'C') && (sit2 == 'A' || sit2 == 'B' || sit2 == 'C') || (sit1 == 'D' || sit1 == 'E') && (sit2 == 'D' || sit2 == 'E')) {
		a[3] = true;
	} if (((sit1 == 'A' || sit1 == 'C') && sit2 == 'B') || (sit1 == 'B' && (sit2 == 'C' || 'A')) || (sit1 == 'D' && sit2 == 'E') || (sit2 == 'D' && sit1 == 'E')) {
		a[4] = true;
	} 
}

int main() {
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	
	memset (a, false, sizeof(a));
	cin >> c1 >> s1 >> c2 >> s2;
	is();
	for (int i = 1; i <= 4; i++) cout << a[i];
	return 0;
}
