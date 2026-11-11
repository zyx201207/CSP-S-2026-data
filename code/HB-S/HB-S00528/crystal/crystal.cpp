#include<bits/stdc++.h>

using namespace std;

using i64 = long long;

i64 rmq[21][510000], n, m, a[510000], sm[510000], log_[510000];

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    log_[1] = 0;
    sm[0] = 0;
    for (int i = 2; i <= n; ++i) {
        log_[i] = log_[i / 2] + 1;
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        sm[i + 1] = a[i] + sm[i];
        rmq[0][i] = a[i];
    }
    for (int i = 1; 1 << i <= n; ++i) {
        for (int j = 0; j < n - (1 << i) + 1; ++j) {
            rmq[i][j] = max(rmq[i - 1][j], rmq[i - 1][j + (1 << (i - 1))]);
        }
    }
    i64 res = 0, l = 0, r = n;
    while (l <= r) {
        i64 mid = (l + r) / 2;
        bool run = false;
        for (int i = 0; i < n - mid + 1; ++i) {
            i64 mx = max(rmq[log_[mid]][i], rmq[log_[mid]][i + mid - (1 << log_[mid])]);
            if (mx * mid - (sm[i + mid] - sm[i]) <= m) {
                run = true;
                break;
            }
        }
        if (run) {
            res = max(res, mid);
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << res << endl;
    return 0;
}

// #include<bits/stdc++.h>

// using namespace std;

// using i64 = long long;

// i64 n, m, a[510000], sm[510000];

// int main() {
//     freopen("crystal4.in", "r", stdin);
//     // freopen("crystal.out", "w", stdout);
//     cin >> n >> m;
//     sm[0] = 0;
//     for (int i = 0; i < n; ++i) {
//         cin >> a[i];
//     }
//     sort(a, a + n);
//     for (int i = 0; i < n; ++i) {
//         sm[i + 1] = a[i] + sm[i];
//     }
//     i64 res = 0;
//     for (i64 i = 0; i < n; ++i) {
//         if (a[i] * (i + 1) - sm[i + 1] <= m) {
//             if (i == 313323) {
//                 cout << (a[i] * (i + 1) - sm[i + 1]) << endl;
//             }
//             res = i + 1;
//         }
//     }
//     cout << res;
//     return 0;
// }