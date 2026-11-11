#include <bits/stdc++.h>

using namespace std;
using ll = long long; 

ifstream fin("travel.in");
ofstream fout("travel.out");

#define cin fin
#define cout fout


int main() {
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	
	string ans;
	if (c1 == c2) {
		ans = ans + "1";
		if ((s1[0] - '0') * 10 + (s1[1] - '0') == (s2[0] - '0') * 10 + (s2[1] - '0')) {
			ans = ans + "1";
			if ((s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C') || (s1[2] >= 'D' && s1[2] <= 'F' && s2[2] >= 'D' && s2[2] <= 'F')) {
				ans = ans + "1";
				if (ll(s1[2] + 1) == ll(s2[2]) || s1[2] - 1 == s2[2]) {
					ans = ans + "1";
				}
			}
		}
	}
	else ans = ans + "0";
	
	while (ans.size() != 4) ans += "0";
	
	cout << ans; 
	return 0;
}
