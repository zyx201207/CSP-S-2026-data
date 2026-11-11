#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string c1, c2, s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int ok1 = 0, ok2 = 0, ok3 = 0, ok4 = 0;
	if (c1 == c2) {
		ok1 = 1;
		if (s1[0] == s2[0] && s1[1] == s2[1]){
			ok2 = 1;
			if (s1[2] == 'A' || s1[2] == 'B' ||s1[2] == 'C')
				if (s2[2] != 'F' && s2[2] != 'D') {
					ok3 = 1;
					if (s1[2] - s2[2] == 1 || s2[2] - s1[2] == 1) ok4 = 1;
				}
			if (s1[2] == 'F' || s1[2] == 'D')
				if (s2[2] != 'A' && s2[2] != 'B' && s2[2] != 'C') {
					ok3 = 1;
					if (s1[2] - s2[2] == 1 || s2[2] - s1[2] == 1) ok4 = 1;
				}
		}
	}
	cout << ok1 << ok2 << ok3 << ok4;
	return 0;
}