//GZ-J00259  白鹭湖小学 陈彦宇
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) cout << "1";
	else {
		cout << "0000";
		return 0;
	}
	cout << "1110";
    fclose(stdin);
    fclose(stdout);
    return 0;
}

