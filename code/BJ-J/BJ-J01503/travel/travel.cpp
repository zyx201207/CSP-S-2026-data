#include <bits/stdc++.h>
using namespace std;
int main () {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string str[4];
    for (int i = 0; i < 4; i++) {
        cin >> str[i];
    }
    if (str[0] == str[2]) {
        cout << "1";
        if (str[1][0] == str[3][0] && str[1][1] == str[3][1]) {
            cout << "1";
            if (str[1][2] == "A" && str[1][2] == "B") cout << "11";
            else if (str[1][2] == "A" && str[3][2] == "C") cout << "10";
            else if (str[1][2] == "B" && str[3][2] == "C") cout << "11";
            else if (str[1][2] == "E" && str[3][2] == "F") cout << "11";
            else if (str[3][2] == "A" && str[1][2] == "C") cout << "10";
            else if (str[3][2] == "B" && str[1][2] == "C") cout << "11";
            else if (str[3][2] == "E" && str[1][2] == "F") cout << "11";
            else cout << "00";
        } else cout << "000";
    } else cout << "0000";
    return 0;
}
