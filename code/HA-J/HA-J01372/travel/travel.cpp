#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int x1 = s1[0] + s1[1];
	int x2 = s2[0] + s2[1];
	int s = s1[2] + s2[2];
	int m = abs(s1[2] - s2[2]);
	
	if (c1 != c2) cout << "0000";
	else {
		if (x1 != x2) cout << "1000";
		else if (s == 138) cout << "1111";
		else if (s1[2] < 'D' && s2[2] < 'D') {
			if (m < 2) cout << "1111";
			else cout << "1110";
		}else cout << "1100";
	}
	return 0;
}
