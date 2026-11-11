#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int c1, c2, r1, r2, co1, co2, f1, f2;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string s1, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    r1 = 10 * (s1[0] - '0') + (s1[1] - '0');
    r2 = 10 * (s2[0] - '0') + (s2[1] - '0');
    co1 = s1[2] - 'A' + 1;
    if (s1[2] == 'D') co1++;
    if (s1[2] == 'D' || s1[2] == 'F') f1 = 2;
    else f1 = 1;
    co2 = s2[2] - 'A' + 1;
    if (s2[2] == 'D') co2++;
    if (s2[2] == 'D' || s2[2] == 'F') f2 = 2;
    else f2 = 1;

    if (c1 == c2) cout << 1;
    else {
        cout << "0000";
        return 0;
    }
    if (r1 == r2) cout << 1;
    else {
        cout << "000";
        return 0;
    }
    if (f1 == f2) cout << 1;
    else {
        cout << "00";
        return 0;
    }
    if (abs(co1 - co2) == 1) cout << 1;
    else cout << "0";
    return 0;
}