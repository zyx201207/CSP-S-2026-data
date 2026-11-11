#include <bits/stdc++.h>
using namespace std;

int b[200005][31];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n / 2; ++i) {
        swap(a[i], a[n - i - 1]);
    }
    
    for (int k = 30; k >= 0; --k) {
        int cnt = 0;
        vector<int> used;
        for (int i = 0; i < a.size(); ++i) {
            int b = (a[i] >> k) & 1;
            if (b == 1) {
                cnt++;
                used.push_back(a[i]);
            }
        }
        if (cnt >= m) {
            swap(a, used);
            used.clear();
        }
    }

    if (a.size() < m) {
        cout << 0 << '\n';
    } else {
        int ans = a[0];
        for (int i = 0; i < m; ++i) {
            ans &= a[i];
        }
        cout << ans << '\n';
    }

    return 0;
}
