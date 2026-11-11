#include <bits/stdc++.h>
using namespace std;

const string Temp = "ABCDE";
bool flag[4];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	string c[4];
	for (int i = 0; i < 4; i++) cin >> c[i];
	
	if (c[0] == c[2]) {
		flag[0] = 1;
		if (c[1].substr(0, 2) == c[3].substr(0, 2)) {
			flag[1] = 1;
			int cnt = 0;
			char id = c[1].back(), idx = c[3].back();
			
			if ((id < 'D' && idx < 'D') || (id > 'C' && idx > 'C')) flag[2] = 1;
			
			for (int i = 0; i < 4; i++) {
				if (i == 2) continue;
				bool k1 = Temp[i] == id || Temp[i] == idx;
				bool k2 = Temp[i+1] == id || Temp[i+1] == idx;
				flag[3] |= k1 && k2;
			}
		}
	}
	
	for (int i = 0; i < 4; i++) {
		if (flag[i]) cout << '1';
		else cout << '0';
	}
	
	
	
	return 0;
}
