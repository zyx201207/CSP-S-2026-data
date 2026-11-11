#include <bits/stdc++.h>
using namespace std;

string c_1, s_1, c_2, s_2;

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    cin >> c_1 >> s_1 >> c_2 >> s_2;

    if (s_1[2] == 'F') {
        s_1[2] = 'E';
    }
    if (s_2[2] == 'F') {
        s_2[2] = 'E';
    }

    cout << (c_1 == c_2);
    cout << ((c_1 == c_2) && (s_1.substr(0, 2) == s_2.substr(0, 2)));
    cout << ((c_1 == c_2) && (s_1.substr(0, 2) == s_2.substr(0, 2)) && (!(min((int)s_1[2], (int)s_2[2]) <= 67 && max((int)s_1[2], (int)s_2[2]) >= 68)));
    cout << ((c_1 == c_2) && (s_1.substr(0, 2) == s_2.substr(0, 2)) && (!(min((int)s_1[2], (int)s_2[2]) <= 67 && max((int)s_1[2], (int)s_2[2]) >= 68)) && (abs((int)s_1[2] - (int)s_2[2]) == 1));
    cout << endl;

    return 0;
}