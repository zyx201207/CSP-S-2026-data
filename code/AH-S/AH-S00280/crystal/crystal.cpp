#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500005;

int n;
long long m;
long long sum[MAXN];
long long a[MAXN];

bool Check(int l, int r) {
    if ( 1ll * (r - l + 1) * a[r] - (sum[r] - sum[l - 1]) <= m ) return 1;
    return 0;
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];

    int l = 1, ans = 1;
    for (int i = 1; i <= n; ++i) {
        while ( !Check(l, i) ) ++l;
        ans = max(ans, i - l + 1);
    }

    cout << ans << endl;
}

/* g++ crystal.cpp -O2 -std=c++14 -static -o crystal.exe */