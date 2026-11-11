# include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 5e5+5;

int n;
LL m, a[N];

int erfen(long long d) {
    int l = 1, r = n, mid, ans=-1;
    while (l <= r) {
        mid = l + r >> 1;
        if (1ll * d * (mid * (mid - 1) / 2) <= m) {
            ans = mid;
            r = mid + 1;
        } else {
            l = mid - 1;
        }

    }
    return ans;
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    long long d = a[2] - a[1];

    cout << erfen(d);
}
