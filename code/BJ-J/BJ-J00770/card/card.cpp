#include <bits/stdc++.h>
using namespace std;
int a[600000], c[400000], d[400000];
bool b[400000];
stack <int> s;
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    if (n <= 500) {
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                if (b[a[j]] == 0) {
                    b[a[j]] = 1;
                    s.push(a[j]);
                }
                else {
                    while (s.top() != a[j]) {
                        b[s.top()] = 0;
                        s.pop();
                    }
                }
            }
            for (int j = 1; j <= m; j++) {
                if (b[j] == 1) {
                    c[j]++;
                    b[j] = 0;
                }
            }
        }
        for (int i = 1; i <= m; i++) {
            cout << c[i] << ' ';
        }
    }
    else {
        int k = 1;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] != k) {
                d[k] = i - 1;
                k++;
            }
        }
        for (int i = 1; i <= m; i++) {
            cout << d[i] << ' ';
        }
    }
    return 0;
}
