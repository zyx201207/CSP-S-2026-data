#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll MAXAxN = 10005;

ll dp[MAXAxN][MAXAxN];

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n;
    cin >> n;

    string s;
    for (ll i = 1; i <= n; ++i) {
        ll tmp;
        char c;
        cin >> tmp >> c;
        for (ll j = 1; j <= tmp; ++j) {
            s += c;
        }
    }

    for (ll len = 2; len <= s.size(); ++len) {
        for (ll i = 1; i <= s.size() - len + 1; ++i) {
            ll j = i + len - 1;
            if (s[i - 1] == s[j - 1]) {
                dp[i][j] = dp[i + 1][j - 1];
            } else {
                dp[i][j] = min({dp[i + 1][j], dp[i][j - 1], dp[i + 1][j - 1]}) + 1;
            }
        }
    }

    cout << dp[1][s.size()];

    return 0;
}