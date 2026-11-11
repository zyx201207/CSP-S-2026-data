#include<bits/stdc++.h>
using namespace std;
string c1, c2, s1, s2;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2) {
		cout << "0000\n";
		return 0;
	}	
	cout << "1";
	if (s1[0] != s2[0] || s1[1] != s2[1]) {
		cout << "000\n";
		return 0;
	}
	cout << "1";
	char ch1 = s1[2], ch2 = s2[2];
	if (((ch1 == 'A' || ch1 == 'B' || ch1 == 'C') && (ch2 == 'D' || ch2 == 'F')) || ((ch1 == 'D' || ch1 == 'F') && (ch2 == 'A' || ch2 == 'B' || ch2 == 'C'))) {
		cout << "00\n";
		return 0;
	}
	cout << "1";
	if (ch1 == 'D' || ch1 == 'F') cout << "1";
	else if ((ch1 == 'A' && ch2 == 'C') || (ch1 == 'C' && ch2 == 'A')) cout << "0";
	else cout << "1";
	fclose(stdin);
	fclose(stdout);
}
