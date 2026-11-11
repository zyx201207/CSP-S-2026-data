#include <bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;

bool cmp(int x, int y, string a, string b) {
	for (int i = x; i <= y; i ++) {
		if (a[i] != b[i]) return false;
	}
	return true;
}

int trans(char a) {
	int ax = a - 'A';
	if (ax == 5) return 4;
	else return ax;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	bool st = cmp(0, 1, c1, c2);
	cout << st;
	
	bool sl = cmp(0, 1, s1, s2);
	cout << (sl && st);
	
	int p1 = trans(s1[2]);
	int p2 = trans(s2[2]);
	
	bool p1f = p1 >= 3, p2f = p2 >= 3;
	bool ss = !(p1f^p2f);
	cout << (ss && st && sl);
	
	cout << (abs(p1 - p2) == 1 && ss && sl && st);
//	cout << p1 << " " << p2 << " " << !(p1f^p2f) <<"\n";
	return 0;
} 
