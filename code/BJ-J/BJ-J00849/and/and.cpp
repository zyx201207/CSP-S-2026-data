#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[200010];
long long ad;
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (m == 1) {
        for (int i = 1; i <= n; i++) {
            ad = max(ad, a[i]);
        }
        cout << ad << endl;
    } else if (m == 2) {
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                ad = max(ad, a[i] & a[j]);
            }
        }
        cout << ad << endl;
    } else if (m == n) {
        ad = a[1];
        for (int i = 2; i <= m; i++) {
            ad = ad & a[i];
        }
        cout << ad << endl;
    } else if (m == 3) {
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                for (int k = j + 1; k <= n; k++) {
                    ad = max(ad, a[i] & a[j] & a[k]);
                }
            }
        }
        cout << ad << endl;
    } else if (m == 4) {
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                for (int k = j + 1; k <= n; k++) {
                    for (int l = k + 1; l <= n; l++) {
                        ad = max(ad, a[i] & a[j] & a[k] & a[l]);
                    }
                }
            }
        }
        cout << ad << endl;
    } else if (m == 5) {
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                for (int k = j + 1; k <= n; k++) {
                    for (int l = k + 1; l <= n; l++) {
                        for (int e = l + 1; e <= n; e++) {
                            ad = max(ad, a[i] & a[j] & a[k] & a[l] & a[e]);
                        }
                    }
                }
            }
        }
        cout << ad << endl;
    } else if (m == 6) {
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                for (int k = j + 1; k <= n; k++) {
                    for (int l = k + 1; l <= n; l++) {
                        for (int e = l + 1; e <= n; e++) {
                            for (int f = e + 1; f <= n; f++) {
                                ad = max(ad, a[i] & a[j] & a[k] & a[l] & a[e] & a[f]);
                            }
                        }
                    }
                }
            }
        }
        cout << ad << endl;
    } else {
        cout << "You are handsome ^_^" << endl;
    }
    return 0;
}
