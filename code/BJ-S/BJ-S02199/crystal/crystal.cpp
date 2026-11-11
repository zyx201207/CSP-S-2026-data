#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;

int n, nextid;
bool isab = true;
long long m, cost, os2, a[500005];

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    if (n == 1) {
        cout << 1;
        return 0;
    } else if (n == 2) {
        a[1] += m;
        if (a[1] < a[2]) {
            cout << 1;
        } else {
            cout << 2;
        }
        return 0;
    }

    os2 = a[2] - a[1];
    for (int i = 3; i <= n; i++) {
        if (isab && a[i] - a[i - 1] != os2) {
            isab = false;
        }
    }

    if (isab) {
        for (int i = 1; ; i++) {
            if (m - cost < os2 * i) {
                while (m - cost >= i) {
                    cost += i;
                }
                cout << i;
                return 0;

            }
            cost += os2 * i;
        }
    }

    while (cost <= m && a[1] != a[n]) {
        for (int i = 1; i < n && (cost <= m && a[1] != a[n]); i++) {
            if (a[i] <= a[i + 1]) {
                nextid = i + 1;
                a[i]++;
                if (a[nextid] != a[i] - 1) {
                    nextid = i;
                }
                cost++;
                if (a[i] <= a[i + 1]) {
                    break;
                }
            }
        }
    }
    for (int i = n; i > 0; i--) {
        if (a[i] == a[nextid]) {
            cout << i;
            return 0;
        }
    }

}
