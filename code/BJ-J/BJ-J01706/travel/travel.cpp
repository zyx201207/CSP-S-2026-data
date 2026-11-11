// travel.cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    // Here We Go!
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;

    string a1, a2;
    char b1, b2;
    a1 = s1.substr(0, 2);
    a2 = s2.substr(0, 2);
    b1 = s1[2];
    b2 = s2[2];

    if (b1 == 'F') b1 = 'E';
    if (b2 == 'F') b2 = 'E';

    bool a, b, c, d;
    a = c1 == c2;
    b = a && a1 == a2;

    c = b && (b1-'A')/3 == (b2-'A')/3;
    d = c && abs(b1 - b2) == 1;

    cout << a << b << c << d << endl;

    return 0;
}
