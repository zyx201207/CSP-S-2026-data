#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    vector<int> cnt(m + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    vector<int> g(m + 1, 0);
    vector<int> du(m + 1, 0);
    g[a[n - 1]] == -1;
    du[a[n - 1]] == -1;
    for (int i = n - 1; i >= 1; --i) {
        if (g[a[i]] == 0) {
            g[a[i]] = a[i + 1];
            du[a[i + 1]]++;
        }
    }
    queue<int> q;
    for (int i = 1; i <= m; ++i) {
        if (du[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int pos = q.front();
        q.pop();
        cnt[g[pos]] += cnt[pos];
        if (--du[g[pos]] == 0) {
            q.push(g[pos]);
        }
    }
    for (int i = 1; i <= m; ++i) {
        cout << cnt[i] << ' ';
    }
    cout << '\n';
    return 0;
}