#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int a[N];

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    unordered_multiset<int> s;
    for (int i = 1; i <= n; i++) s.insert(a[i]);
    for (int i = 29; i >= 0; i--) {
        int cnt = 0;
        for (auto j : s) {
            if (j & (1 << i)) cnt++;
        }
        if (cnt >= m) {
            vector<int> v;
            for (auto j : s) v.push_back(j);
            for (auto j : v) if (!(j & (1 << i))) s.erase(j);
        }
    }
    int ans = (1 << 30) - 1;
    for (auto i : s) ans = ans & i;
    cout << ans << "\n";
    return 0;
}