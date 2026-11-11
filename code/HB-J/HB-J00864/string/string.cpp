#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
string s = "";
vector<vector<int>> dp;

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a; char b;
        cin >> a >> b;
        for (int j = 0; j < a; ++j)
            s += b;
    }
    cout << s << '\n';
    dp.assign(s.size(), vector<int>(s.size(), 0));
    for (int i = 0; i < n - 1; ++i)
        if (s[i] != s[i + 1])
            dp[i][i + 1] = 1;
    for (int len = 3; len <= s.size(); ++len)
        for (int i = 0; i < s.size() - len + 1; ++i) {
            int j = i + len - 1;
            if (s[i] == s[j])
                dp[i][j] = min(dp[i + 1][j - 1], min(dp[i + 1][j], dp[i][j - 1]));
            else
                dp[i][j] = dp[i + 1][j - 1] + 1;
        }
    cout << dp[0][s.size() - 1];
    return 0;
}