#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5, MAXM = 3e5 + 5;
int n, m, p[MAXN], k[MAXN], idx[MAXM], cn[MAXM];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        bool flag = false;
        memset(idx, 0, sizeof idx);
        memset(k, 0, sizeof k);
        for (int j = i; j <= n; j++) {
            if (idx[p[j]] == 0) {
                idx[p[j]] = cnt + 1;
                k[++cnt] = p[j];
                cn[p[j]]++;
            } else  {
                for (int t = idx[p[j]] + 1; t <= cnt; t++) {
                    idx[k[t]] = 0;
                    cn[t[k]]--;
                    k[t] = 0;
                }
                cnt = idx[p[j]];
            }
        }
    }
    for (int i = 1; i < m; i++) cout << cn[i] << ' ';
    cout << cn[m];
    cout << '\n';
    return 0;
}
