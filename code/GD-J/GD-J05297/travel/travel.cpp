#include <bits/stdc++.h>
using namespace std; 

string c1, s1, c2, s2;
int dir[5] = {0, 0, 0, 1, 1};
bool ans[4];
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) {
		ans[0] = true;
		if(s1.substr(0, 2) == s2.substr(0, 2)) {
			ans[1] = true;
			if(dir[s1[2] - 'A'] == dir[s2[2] - 'A']) {
				ans[2] = true;
				if(s1[2] + 1 == s2[2] || s2[2] + 1 == s1[2]) ans[3] = true;
			}
		}
	}
	for(int i = 0; i <= 3; i++) cout << ans[i];
	return 0;
}
