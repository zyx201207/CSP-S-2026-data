#include <bits/stdc++.h>
#define debug(x) cerr << #x << " " << x << '\n';

using namespace std;

typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, char>> s(n);
    for (auto& p : s) {
        cin >> p.first >> p.second;
    }
    ll ans = 0;
    for (int i = 0, j = n - 1; i < j;) {
        int& x1 = s[i].first;
        char& y1 = s[i].second;
        int& x2 = s[j].first;
        char& y2 = s[j].second;
        if (x1 == x2) {
            if (y1 != y2) {
                ans += x1;
            }
            i++, j--;
        } else {
            if (x1 < x2) {
                if (y1 != y2) {
                    ans += x1;
                }
                x2 -= x1;
                i++;
            } else {
                if (y1 != y2) {
                    ans += x2;
                }
                x1 -= x2;
                j--;
            }
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}