#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2) {
		cout << "0000";
		return 0;
	}
	cout << 1;
	
	
	if((s1[0] != s2[0]) || (s1[1] != s2[1])) {
		cout << "000";
		return 0;
	}
	cout << 1;
	
	int a = s1[s1.size() - 1] - 'A';
	int b = s2[s2.size() - 1] - 'A';
	if(a <= 2 && b <= 2 || (a > 2 && b > 2))
		cout << 1;
	else {
		cout << "00";
		return 0;
	}
	
	if((a == b + 1) || (a == b - 1))
		cout << 1;
	else 
		cout << 0;
	return 0;
}
