#include <bits/stdc++.h>
using namespace std;
struct m {
    long long l;
    char c;
};
m a[300000];
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    long long cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].l >> a[i].c;
    }
    int z = 1, y = n;
    while (z != y) {
        if (a[z].l > a[y].l) {
            if (a[z].c != a[y].c) {
                cnt += a[y].l;
            }
            a[z].l -= a[y].l;
            y--;
        }
        else if(a[z].l < a[y].l) {
            if (a[z].c != a[y].c) {
                cnt += a[z].l;
            }
            a[y].l -= a[z].l;
            z++;
        }
        else {
            if (a[z].c != a[y].c) {
                cnt += a[z].l;
            }
            a[z].l = 0;
            y--;
        }
    }
    cout << cnt;
    return 0;
}