#include <bits/stdc++.h>
using namespace std;

string r[2], x[2];
int cnt;
unordered_map<char, int> mp;

void init() {
	mp['A'] = mp['B'] = mp['C'] = 1;
	mp['D'] =  mp['F'] = 2;
}

bool beside() {
	if (cnt != 3) return 0;
	if (mp[r[1][2]] == mp[x[1][2]]) {
		if (mp[r[1][2]] == 2) return 1;
		if (abs(r[1][2] - x[1][2]) == 1) return 1;
	}
	return 0;
}

int main() { // Trick||Treat! 
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	init();
	cin >> r[0] >> r[1] >> x[0] >> x[1];
	if (r[0] == x[0]) {
		cout << 1;
		cnt++;
	} else {
		cout << 0;
	}
	if (r[1][0] == x[1][0] && r[1][1] == x[1][1] && cnt) {
		cout << 1;
		cnt++;
	} else {
		cout << 0;
	}
	if (mp[r[1][2]] == mp[x[1][2]] && cnt == 2) {
		cout << 1;
		cnt++;
	} else {
		cout << 0;
	}
	cout << beside();
	return 0;
}
