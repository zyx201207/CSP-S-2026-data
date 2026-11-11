#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
bool check1 () {
    bool a = 0, b = 0;
    if (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') a = 1;
    if (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') b = 1;
    return a == b;
}
bool check2 () {
    char a = s1[2], b = s2[2];
    if (a > b) swap(a, b);
    if (a == 'D' && b == 'F') return 1;
    return (a + 1) == b;
}
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << "1";
		if (s1[0] == s2[0] && s1[1] == s2[1]) {
            cout << "1";
            if (check1()) {
                cout << "1";
                if (check2()) cout << "1";
                else cout << "0";
            } else cout << "00";
		} else cout << "000";
	} else {
        cout << "0000";
	}
}
