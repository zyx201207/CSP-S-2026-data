#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> vecs[2];
const int mxN = 2e3 + 5;
int vis[mxN][mxN];
int xi[mxN];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    ++t;
    while (--t) {
        int n, d;
        cin >> n >> d;
        for (int i = 0; i < n; ++i)
            cin >> xi[i];
        vector<pair<int, int>> *cur = vecs + 0, *nxt = vecs + 1;
        cur->clear();
        nxt->clear();
        for (int l = 0; l < n; ++l)
            for (int r = l + 1; r < n; ++r)
                if (xi[r] - xi[l] > d)
                    break;
                else
                    cur->push_back({l, r});
        int ans = 0;
        for (int m = 1; m < n; ++m) {
            sort(cur->begin(), cur->end());
            int l = -1, r = -1;
            int cnt = 0;
            for (auto &pr : *cur) {
                if (l == -1)
                    l = pr.first, r = pr.second;
                if (pr.first != l || pr.second != r) {
                    if (cnt == 2 && vis[l][r] != t)
                        ++ans;
                    cnt = 1;
                    vis[l][r] = t;
                    l = pr.first, r = pr.second;
                } else
                    ++cnt;
            }
            for (auto &pr : *cur) {
                int &ol = pr.first, &olr = pr.second;
                for (int r = olr + 1; r < n; ++r) {
                    if (xi[r] - xi[olr] > d)
                        break;
                    else
                        nxt->push_back({ol, r});
                }
            }
            cur->clear();
            swap(cur, nxt);
        }
        cout << ans << endl;
    }
}
