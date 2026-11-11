//GZ-J00448 ∫Î“„÷–—ß ¡ı„‰√˙ 
#include <bits/stdc++.h>
using namespace std;

string c1, c2, s1, s2;
int c, p, tc, xl;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	for (int t = 0; t < 3; t++) {
		if (c1[t] != c2[t]){
			c = 0;
			break;
		}
		else c = 1;
	}
	
	if (c == 1){
		for (int t = 0; t < 2; t++) {
			if (s1[t] != s2[t]){
				p = 0;
				break;
			}
			else p = 1;
		}
	}
	
	
	if (c == 1) {
		if ((p == 1) && (((s1[2] <= 'C') && (s2[2] <= 'C'))
		|| ((s1[2] >= 'D') && (s2[2] >= 'D')))) tc = 1;
	}
	
	if (c == 1) {
		if ((p == 1) && (tc == 1)) {
			if (s1[2] <= 'C')
				 if ((s1[2] == 'B') || (s2[2] == 'B'))  xl = 1;
			else if ((s1[2] >= 'D') && (s2[2] >= 'D')) xl = 1;
		}
	}
	
	
	cout << c << p << tc << xl << "\n";
	
	return 0;
}
