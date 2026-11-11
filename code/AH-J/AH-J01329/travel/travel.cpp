#include <bits/stdc++.h>
using namespace std;
bool arr[10][10] = {
	{0, 1, 1, 0, 0}, 
	{1, 0, 1, 0, 0}, 
	{1, 1, 0, 0, 0}, 
	{0, 0, 0, 0, 1}, 
	{0, 0, 0, 1, 0}
	};
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2) {
		cout << "0000\n";
		return 0;
	}
	cout << 1;
	if (s1[0] != s2[0] || s1[1] != s2[1]) {
		cout << "000\n";
		return 0;
	}
	cout << 1;
	if (arr[s1[2] - 'A'][s2[2] - 'A'] == 0 && arr[s2[2] - 'A'][s1[2] - 'A'] == 0) {
		cout << "00\n";
		return 0;
	}
	cout << 1;
	if (s1[2] - 1 == s2[2] || s1[2] + 1 == s2[2]) cout << "1\n";
	else cout << "0\n";
	return 0;
}
