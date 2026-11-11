# include <bits/stdc++.h>
using namespace std;

int main () {
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	
	
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	
	if (c1 == c2) {
		cout << 1;
	} else {
		cout << "0000";
		return 0;
	}
	
	int sum1 = 0, sum2 = 0;	
	for (int i = 0; i < 2; i++) {
		sum1 += s1[i] - '0';
		sum1 *= 10;
		sum2 += s2[i] - '0';
		sum2 *= 10;
	}
	
	if (sum1 == sum2) {
		cout << 1;
	} else {
		cout << 0;
	}
	
	int p1, p2;
	
	if (s1[2] - 'A' <= 2) {
		p1 = 1;
	} else {
		p1 = 0;
	}
	
	if (s2[2] - 'A' <= 2) {
		p2 = 1;
	} else {
		p2 = 0;
	}
	
	if (sum1 == sum2) {
		if (p1 == p2) {
			cout << 1;
		} else {
			cout << 0;
		}
	} else {
		cout << 0;
	}

	char a1 = s1[2], a2 = s2[2];
	
	if ((a1 == 'C' && a2 == 'D') || (a1 == 'D' && a2 == 'C')) {
		cout << 0;
		return 0;
	}
	
	if (((a1 == 'D' && a2 == 'F') || (a1 == 'F' && a2 == 'D')) && sum1 == sum2) {
		cout << 1;
		return 0;
	}
	
	if (((a1 - 1) == a2 || (a1 + 1) == a2) && sum1 == sum2 || ((sum1 + 1) == sum2 || (sum1 - 1) == sum2) && a1 == a2) {
		cout << 1;
	} else {
		cout << 0;
	}
	
	cout << endl;
	return 0;
} 

// 52´ºÒâ 
