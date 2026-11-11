#include <bits/stdc++.h>

using namespace std;

bool check (int k1, int k2) {
    if ((k1 >= 1 && k1 <= 3 && k2 >= 1 && k2 <= 3) ||
        (k1 >= 4 && k1 <= 5 && k2 >=4 && k2 <= 5)) {
        return 1;
    }
    else return 0;
}

int main() {

    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    string s1, c1, s2, c2;
    cin >> s1 >> c1 >> s2 >> c2;


    if (s1 != s2) {
        cout << "0000";
        return 0;
    }

    int num1 = c1[0] * 10 + c1[1];
    int num2 = c2[0] * 10 + c2[1];

    if (num1 != num2) {
        cout << "1000";
        return 0;
    }

    int k1 = c1[2] - 'A' + 1;
    int k2 = c2[2] - 'A' + 1;


    if (!check(k1, k2)) {
        cout << "1100";
        return 0;
    }
    if (abs(k2 - k1) != 1)  {
        cout << "1110";
        return 0;
    }
    else cout << "1111";


    return 0;
}
