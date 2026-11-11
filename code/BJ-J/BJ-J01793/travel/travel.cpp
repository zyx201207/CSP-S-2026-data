#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;

    bool c = c1 == c2;
    cout << c;

    c = c && (s1[0] == s2[0] && s1[1] == s2[1]);
    cout << c;

    c = c && (s1[2] <= 'C') == (s2[2] <= 'C');
    cout << c;

    c = c && (s1[2] == s2[2] + 1 || s1[2] == s2[2] - 1);
    cout << c;

    return 0;
}