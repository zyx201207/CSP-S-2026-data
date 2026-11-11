#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
const int M = 3e5 + 5;
int l[N], r[N], a[N];
int ans[M], lst[M];
bool inl[N];
signed main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 5000; j++) inl[j] = 0, lst[j] = j;
        for (int j = i; j <= n; j++) l[j] = j-1, r[j] = j+1;
        r[11451] = i; l[i] = 11451, l[11451] = 0;
        for (int j = i; j <= n; j++) {
            int x = a[j];
            if (inl[a[j]]) {
                r[l[lst[x]]] = j;
                l[j] = l[lst[x]];
                //l[lst[x]] = 0;
                r[lst[x]] = 0;
                //cout << lst[x];
            }
            lst[x] = j;
            inl[x] = 1;
        }//cout << i << ":\n";
        for (int p = 11451; p; p = r[p]) {
            //cout << a[p] << "->";
            ans[a[p]]++;
        }
        //cout << '\n';
    }
    for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
    return 0;
}
