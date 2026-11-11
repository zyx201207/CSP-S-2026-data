#include <bits/stdc++.h>
using namespace std;

long long n, m;
long long a[200000], cnt[200000], z[200000];

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (cnt[a[i]] != 0) {
            for (int j = 0; j < n; j++) {
                z[j] = 0;
            }
            z[a[i]] = 1;
        }
        cnt[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (cnt[a[i]] != 0) {
                for (int j = 0; j < n; j++) {
                    z[j] = 0;
                }
            }
            z[a[i]] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << cnt[i];
    }
    return 0;
}
