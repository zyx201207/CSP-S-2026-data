#include <bits/stdc++.h>
using namespace std;

int main() {
	bool f = false, f1 = false, f2 = false, f3 = false; // f在同一节车厢， f2同一排，f3在同一侧 , f1 在df侧 
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {//在同一节车厢 
		cout << 1;
		f = true;
	}
	else cout << 0;
	
	string t1 = s1.substr(0, 2), t2 = s2.substr(0, 2);
	if (t1 == t2 && f) {//在同一排 
		cout << 1;
		f2 = true;
	}
	else cout << 0;
	
	char t3 = s1[2], t4 = s2[2];
	if (t3 == 'A' || t3 == 'B' || t3 == 'C' && f && f2) {//在同一侧 
		if ((t4 == 'A' || t4 == 'B' || t4 == 'C') && f && f2) {
			cout << 1;
			f3 = true;
		}
		else cout << 0;
	} else {
		if (t4 == 'D' || t4 == 'F' && f && f2) {
			cout << 1;
			f3 = f1 = true;
		}
		else cout << 0;
	}
	
	if (f1 && f && f3 && f2) cout << 1;//相邻 
	else {
		if ((t3 == 'A' && t4 == 'B' || t4 == 'A' && t3 == 'B' || t3 == 'C' && t4 == 'B' || t4 == 'C' && t3 == 'B') && f2 && f && f3) cout << 1;
		else cout << 0;
	}
	return 0;
} 
