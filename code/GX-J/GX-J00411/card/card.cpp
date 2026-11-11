#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, m, a[N], b[N], c[N], d[N], e[N];
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
        e[i] = b[i];
    }
    bool f = 1;
    sort(b + 1, b + n + 1);
    for(int i = 1; i <= n; i++) {
        if(a[i] != b[i]) {
            f = 0;
            break;
        }
    }
    if(f) {
        for(int i = 1; i <= n; i++) {
            if(a[i] == a[i + 1]) {
                while(a[i] == a[i + 1]) {
                    i++;
                }
            }
            cout << i << ' ';
        }
        return 0;
    }
    bool f1[N] = {0};
    for(int k = 1; k <= n; k++) {
        memset(c, 0, sizeof(c));
        memset(f1, 0, sizeof(f1));
        for(int i = k; i <= n; i++) a[i] = e[i];
        for(int i = 1; i <= n; i++) {
            if(c[a[i]] == 0) c[a[i]]++;
            else {
                int j = i - 1;
                while(a[j] != a[i] && j > 0) {
                    c[a[j]] = 0;
                    a[j] = 0;
                    j--;
                }
                a[j] = 0;
            }
        }
        for(int i = k; i <= n; i++) {
            if(a[i] != 0 && f1[a[i]] == 0) {
                d[a[i]]++;
                f1[a[i]] = 1;
            }
        }
    }
    for(int i = 1; i <= m; i++) {
        cout << d[i] << ' ';
    }
    return 0;
}
