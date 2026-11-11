#include <bits/stdc++.h>
#define int long long
#define rep(i, s, t) for (int i = s; i <= t; i++)
#define pre(i, s, t) for (int i = s; i >= t; i--)
using namespace std;
const int N = 2e5 + 2;
int n, m, a[N];
signed main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m; vector<int> st; int res = 0;
    rep(i, 1, n) cin >> a[i], st.push_back(a[i]);
    pre(i, 30, 0) {
        vector<int> ns;
        for (int x : st) if ((x >> i) & 1) ns.push_back(x);
        if (ns.size() >= m) res += (1 << i), st = ns;
    }
    cout << res << '\n';
    return 0;
}
/*
D:\GD-J04790\and\and.exe
*/