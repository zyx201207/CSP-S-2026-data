#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
vector<bool> ans(4);
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2) {
        ans[0] = true;
        if (s1.substr(0, 2) == s2.substr(0, 2)) {
            ans[1] = true;
            bool isABC = (('A' <= s1[2] && s1[2] <= 'C') && ('A' <= s2[2] && s2[2] <= 'C'));
            bool isDF = ((s1[2] == 'D'|| s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F'));
            if (isABC || isDF) {
                ans[2] = true;
                if (isABC && abs(s1[2] - s2[2]) == 1) {
                    ans[3] = true;
                }
                if (isDF && abs(s1[2] - s2[2]) == 2) {
                    ans[3] = true;
                }
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        cout << ans[i];
    }
    cout << "\n";
    return 0;
}
