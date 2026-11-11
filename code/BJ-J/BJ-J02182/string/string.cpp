#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
struct Node{
    long long x;
    char c;
}a[N];

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].c;
    }
    int l = 1, r = n;
    long long lx = a[1].x, rx = a[n].x;
    long long ans = 0;
    while (l < r) {
        if (rx > lx) {
            if (a[r].c != a[l].c) {
                ans += lx;
            }
            rx -= lx;
            l += 1;
            lx = a[l].x;
        } else {
            if (rx < lx) {
                if (a[r].c != a[l].c) {
                    ans += rx;
                }
                lx -= rx;
                r -= 1;
                rx = a[r].x;
            } else {
                if (a[r].c != a[l].c) {
                    ans += rx;
                }
                l += 1;
                lx = a[l].x;
                r -= 1;
                rx = a[r].x;
            }
        }
    }
    cout << ans;
    return 0;
}