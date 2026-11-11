#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int c1, c2;
string s1, s2;

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> c1 >> s1 >> c2 >> s2;
    string ans(4, '0');
    if (c1 == c2) {
        ans[0] = '1';
        if (s1[0] == s2[0] && s1[1] == s2[1]) {
            ans[1] = '1';
            if ((s1[2] <= 'C') == (s2[2] <= 'C')) {
                ans[2] = '1';
                if ((s1[2] == 'C' && s2[2] == 'D') || (s1[2] == 'D' && s2[2] == 'C'))
                    { cout << ans; return 0;                                 }
                if ((s1[2] - s2[2] == -1 || s1[2] - s2[2] == 1))
                    ans[3] = '1';
            }
        }
    }
    cout << ans;
    return 0;
}