#include<bits/stdc++.h> 
using namespace std;

string c1, s1, c2, s2;
bool flag[10];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	if (c1[0] == c2[0] && c1[1] == c2[1]) {
		cout << "1";
		flag[1] = 1;
	}
	else {
		cout << "0";
	}
	
	if (flag[1] && s1[0] == s2[0] && s1[1] == s2[1]) {
		cout << "1";
		flag[2] = 1;
	}
	else {
		cout << "0";
	}
	
	int a = s1[2] - 'A' + 1, b = s2[2] - 'A' + 1;
	
	if (flag[2] && ((a <= 3 && b <= 3) || (a >= 4 && b >= 4))) {
		flag[3] = 1;
		cout << "1";
	}
	else {
		cout << "0";
	}
	
	if (flag[3] && ((a == b + 1) || (a == b - 1))) {
		cout << "1";
	}
	else {
		cout << "0";
	}
	
	return 0;
}
