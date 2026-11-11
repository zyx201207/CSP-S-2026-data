#include<bits/stdc++.h>
using namespace std;
const int MAXN = 500000;

int n;
long long m;
long long a[MAXN];

bool check(int x) {
    long long cnt = 0;

    for(int i = 0; i < x; ++i) {
        cnt += (a[x] - a[i]);
        if(cnt > m) {
            return 0;
        }
    }
    return 1;
}

int main() {

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a, a + n);

    int l = 0, r = n - 1;
    while(l <= r) {
        int mid = r + (l - r) / 2;
        if(check(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << l << '\n';

    return 0;
}
