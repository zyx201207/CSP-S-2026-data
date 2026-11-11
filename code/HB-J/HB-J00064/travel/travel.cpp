#include <bits/stdc++.h>
using namespace std;

int c1, c2; string s1, s2;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s2 >> c2 >> s2;
    int a1 = (s1[0] - '0') * 10 + (s1[1] - '0'), a2 = (s1[0] - '0') * 10 + (s1[1] - '0');
    int b1 = s1[3] - 'A' + 1, b2 = s2[3] - 'A' + 1;
    bool a = (c1 == c2), b = (a1 == a2), c = ((b1 <= 3 && b2 <= 3) || (b1 > 3 && b2 > 3)), d = (abs(b1 - b2) == 1);
    cout << a << (a && b) << (a && b && c) << (a && b && c && d);
    return 0;
}
