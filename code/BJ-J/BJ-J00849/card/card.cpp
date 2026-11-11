#include <bits/stdc++.h>
#include <deque>
using namespace std;
int n, m;
int mp[3010];
int a[5010];
int w[10010];
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        memset(w, 0, sizeof(w));
        int cnt = 1;
        for (int j = i; j <= n; j++) {
            int flag = 0;
            for (int k = 1; k <= cnt; k++) {
                if (w[k] == a[j]) {
                    flag = 1;
                    for (int l = k + 1; l <= cnt; l++) {
                        w[l] = 0;
                    }
                    cnt = k;
                    break;
                }
            }
            if (!flag) {
                w[cnt++] = a[j];
            }
        }
        for (int j = 1; j <= cnt; j++) {
            mp[w[j]]++;
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << mp[i] << " ";
    }
    return 0;
}
