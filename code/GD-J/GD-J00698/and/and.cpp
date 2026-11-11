#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
const int V = 3e1;
int n, m, a[N];

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> s;
    for (int i = 1; i <= n; i++) s.push_back(a[i]);
    int ans = 0;
    for (int i = V; i >= 0; i--) {
        vector<int> t;
        for (auto j : s) if ((j >> i) & 1) t.push_back(j);
        if (t.size() >= m) ans += 1 << i, s = t; 
    }
    return cout << ans, 0;
}