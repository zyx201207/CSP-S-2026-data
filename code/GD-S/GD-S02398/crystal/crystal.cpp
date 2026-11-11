#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a;
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    bool okA = true; // 依旧骗分
    cin >> n >> m;
    a.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
		cin >> a[i];
        if (a[i] != i) {
            okA = false;
        }
	}
    if (okA) {
        // For sequences like [1, 2, 3, 4, 5, 6, ..., n].
        int ans = 1;
        for (int i = 1; i <= n && m - i >= 0; i++) {
            m -= i;
            ++ ans;
        }
        cout << ans << "\n";
    } else {
        cout << 1 << "\n";
    }
    return 0;
}
