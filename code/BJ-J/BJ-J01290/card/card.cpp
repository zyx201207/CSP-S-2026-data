#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<int>a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<long long>ans(m + 1, 0);
    for (int i = 1; i <= n; i++) {
        vector<int>b;
        b.push_back(0);
        for (int j = i; j <= n; j++) {
            for (int k = 1; k < b.size(); k++) {
                if (b[k] == a[j]) {
                    b.erase(b.begin() + k, b.end());
                    break;
                }
            }
            b.push_back(a[j]);
        }
        for (int i = 1; i < b.size(); i++) {
            if (b[i] <= m) {
                ans[b[i]]++;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
