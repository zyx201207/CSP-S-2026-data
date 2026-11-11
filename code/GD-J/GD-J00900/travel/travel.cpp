#include <bits/stdc++.h>
using namespace std;
map<char, int> mp = {{'A', 1}, {'B', 2}, {'C', 3}, {'D', 4}, {'F', 5}};
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int a = 0;
	for(int i = c1.size() - 1; i >= 0; i --) {
		a = a * 10 + c1[i];
	}
	int b = 0;
	for(int i = c2.size() - 1; i >= 0; i --) {
		b = b * 10 + c2[i];
	}
	int c = 0;
	for(int i = s1.size() - 2; i >= 0; i --) {
		c = c * 10 + s1[i];
	}
	int d = 0;
	for(int i = s2.size() - 2; i >= 0; i --) {
		d = d * 10 + s2[i];
	}
	if(a == b) {
		cout << 1;
		if(c == d) {
			cout << 1;
			if((mp[s1[2]] <= 3 && mp[s2[2]] <= 3) || (mp[s1[2]] > 3 && mp[s2[2]] > 3)) {
				cout << 1;
				if(abs(mp[s1[2]] - mp[s2[2]]) == 1) {
					cout << 1;
				} else {
					cout << 0; 
				}
			} else {
				cout << "00";
			}
		} else {
			cout << "000";
		}
	} else {
		cout << "0000";
	}
	return 0;
}
