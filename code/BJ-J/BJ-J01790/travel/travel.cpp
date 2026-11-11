#include <bits/stdc++.h>
using namespace std;
int c1, c2;
string s1, s2;
inline int to_numbers(char c) {
    return c - 'A' + 1;
}
inline bool is_typ(int a, int b) {
    return (a <= 3 && b <= 3) || (a > 3 && b > 3);
}
inline bool is_next(int a, int b) {
    return is_typ(a, b) && abs(a - b) == 1; 
}
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    cout << (c1 == c2);
    int k1, k2;
    k1 = (s1[0] - '0') * 10 + s1[1] - '0';
    k2 = (s2[0] - '0') * 10 + s2[1] - '0';
    cout << (c1 == c2 && k1 == k2);
    cout << (c1 == c2 && k1 == k2 && is_typ(to_numbers(s1[2]), to_numbers(s2[2])));
    cout << (c1 == c2 && k1 == k2 && is_next(to_numbers(s1[2]), to_numbers(s2[2])));
    // cout << "k1: " << k1 << " " << "k2: " << k2;
    return 0;
}