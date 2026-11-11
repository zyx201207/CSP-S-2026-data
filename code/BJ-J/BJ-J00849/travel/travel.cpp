#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int ans[5];
int to_digit(string s) {
    int sum = 0;
    for (int i = 0; i < s.size(); i++) {
        sum = sum * 10 + (s[i] - '0');
    }
    return sum;
}
int to_digit2(string s) {
    int sum = 0;
    for (int i = 0; i < s.size() - 1; i++) {
        sum = sum * 10 + (s[i] - '0');
    }
    return sum;
}
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    int cnum1 = to_digit(c1);
    int snum1 = to_digit2(s1);
    int cnum2 = to_digit(c2);
    int snum2 = to_digit2(s2);
    char c = s1[2];
    char s = s2[2];
    int a = c - 'A';
    int b = s - 'A';
    if (cnum1 == cnum2) {
        ans[0] = 1;
    }
    if (cnum1 == cnum2 && snum1 == snum2) {
        ans[1] = 1;
        if (c >= 'A' && c <= 'C' && s >= 'A' && s <= 'C') {
            ans[2] = 1;
            if (abs(a - b) == 1) {
                ans[3] = 1;
            }
        } else if (c >= 'D' && c <= 'F' && s >= 'D' && s <= 'F') {
            ans[2] = 1;
            if (abs(a - b) == 1) {
                ans[3] = 1;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        cout << ans[i];
    }
    return 0;
}
