#include <bits/stdc++.h>
using namespace std;

int n, m, cnt, ans;
int a[200005];
vector<int> mp[31];

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[30].push_back(a[i]);
    }

    for (int i = 29; i >= 0; i--) {
        vector<int> tmp;

        for (auto j : mp[i + 1]) {
            if ((j >> i) & 1) {
                tmp.push_back(j);
            }
        }

        if (tmp.size() >= m) {
            ans |= (1 << i);
            mp[i] = tmp;
        } else {
            mp[i] = mp[i + 1];
        }
    }

    cout << ans << endl;

    return 0;
}