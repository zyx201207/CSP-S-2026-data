#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) {
		cout << 1;
		if(s1[0] == s2[0] && s1[1] == s2[1]) {
			cout << 1;
			if((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] > 'C' && s2[2] > 'C')) {
				cout << 1;
				if(abs((int)(s1[2] - s2[2]) <= 1)) {
					cout << 1;
				} else {
					cout << 0;
				}
			} else {
				for(int i = 1; i <= 2; i ++) {
					cout << 0;
				}
			}
		} else {
			for(int i = 1; i <= 3; i ++) {
				cout << 0;
			}
		}
	} else {
		for(int i = 1; i <= 4; i ++) {
			cout << 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
