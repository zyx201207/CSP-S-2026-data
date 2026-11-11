#include <bits/stdc++.h>

using namespace std;
using LL = long long;

string c1, c2, c3, c4;
int p1, p2;

vector<int> ver[10];

void init() {
	ver[0].push_back(1);
	ver[1].push_back(0), ver[1].push_back(2);
	ver[2].push_back(1);
	ver[3].push_back(5);
	ver[5].push_back(3);
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> c1 >> c2 >> c3 >> c4; init();
	if (c1 == c3) {
		cout << 1;
	}
	else {
		cout << "0000";
		return 0;
	}
	for (int i = 0; i < (int)c2.size(); ++i) {
		if (!isdigit(c2[i])) 
			break;
		p1 = p1 * 10 + (c2[i] - '0');
	}
	for (int i = 0; i < (int)c4.size(); ++i) {
		if (!isdigit(c4[i]))
			break;
		p2 = p2 * 10 + (c4[i] - '0');
	}
	if (p1 == p2) {
		cout << 1;
	}
	else {
		cout << "000";
		return 0;
	}
	int l1 = c2[c2.size() - 1] - 'A', l2 = c4[c4.size() - 1] - 'A'; int k = 0;
	if (((l1 < 3 && l2 < 3) || (l1 >= 3 && l2 >= 3)) && p1 == p2) {
		cout << 1;
	}
	else {
		cout << "00";
		return 0;

	} bool flag = false;
	for (int kkk : ver[l1]) {
		if (kkk == l2)
			flag = true;
	}
	cout << flag;
	return 0;
}
