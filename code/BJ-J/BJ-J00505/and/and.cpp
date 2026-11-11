#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e5 + 10;
const int maxm = 40;
const int inf = 0x3f3f3f3f3f3f3f3f;
int n, m, a[maxn], ans;
vector<int> g[maxn], vec;
signed main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int bit = 0; bit <= 35; bit++)
            if ((a[i] >> bit) & 1) g[bit].push_back(a[i]);
        vec.push_back(a[i]);
    }
    for (int bit = 0; bit <= 35; bit++) {
        sort(g[bit].begin(), g[bit].end());
    }
    sort(vec.begin(), vec.end());
    for (int bit = 35; bit >= 0; bit--) {
        if (g[bit].size() < m) continue;
        vector<int> a = vec, b = g[bit], c;
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] < b[j]) i++;
            else if (a[i] > b[j]) j++;
            else c.push_back(a[i]), i++, j++;
        }
        if (c.size() < m) continue;
        vec = c;
        ans |= (1 << bit);
    }
    cout << ans << "\n";
    return 0;
}