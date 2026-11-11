// crystal.cpp

#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 7;
int a[N];
int n, m;


bool check(int x) {
    // x 个行不行 O(n)
    long long sum = 0;
    for (int i = 1; i <= x; i++) {
        sum += a[x] - a[i];
    }

    if (sum <= m) return true;

    for (int i = x+1; i <= n; i++) {
        sum -= (a[i-1] - a[i-x]);
        sum += (a[i] - a[i-1]) * (x-1);

        if (sum <= m) return true;
    }

    return false;
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a+1, a+n+1);

    int l = 1, r = n; // log(n)
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            l = mid+1;
        } else {
            r = mid;
        }
    }

    cout << l-1 << endl;

    return 0;
}
