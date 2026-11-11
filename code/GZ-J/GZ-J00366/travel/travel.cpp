//GZ-J00366 贵阳市第一实验中学 孟杰锐 
#include <bits/stdc++.h>

using namespace std;

string a, b, c, d;
int cnt, cnt2, cnt3, cnt4;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> a >> b >> c >> d;
	if (a == c) cout << 1;
	else cout << 0;
	
	int sumn = max(b.size(), d.size());
	
	for (int i = 0; i < sumn; i++) {
		if (b[i] >= '0' && b[i] <= '9' || d[i] >= '0' && d[i] <= '9') {
			if (b[i] == d[i]) cnt = 1;
			else cnt = 0;
		}
	}
	
	cout << cnt;
	
	for (int i = 0; i < sumn; i++) {
		if (cnt == 1) {
			if (b[i] >= 'A' && b[i] <= 'C' && d[i] >= 'A' && d[i] <= 'C') {
				cnt2 = 1;
				cnt3 = 1;
			}
			else if((b[i] == 'D' || b[i] == 'F') && (d[i] == 'D' || b[i] == 'F')) {
				cnt2 = 1;
				cnt3 = 0;
			}
		}
	}
	
	cout << cnt2;
	
	for (int i = 0; i < sumn; i++) {
		if (cnt3 == 1) {
			if (b[i] >= 'A' && b[i] <= 'C' && d[i] >= 'A' && d[i] <= 'C') {
				if (char(b[i] + 1) == d[i]) cnt4 = 1;
				else cnt4 = 0;
			}
		}
	}
	
	cout << cnt4;
	
	return 0;
} 
