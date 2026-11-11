#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

long long n, m;
long long a[N];

bool cmp(long long x, long long y) {
    return x > y;
}

long long f(long long x) {
    int ans = 0;
    while(x != 0) {
        ans++;
        x /= 2;
    }
    return ans;
}

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(long long i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a+1, a+n+1, cmp);
    long long st = 1;
    if(f(a[1]) != f(a[2]) && ((a[1]&a[2]) <= (a[2]&a[3]))) st = 2;
    long long ans = a[1];
    for(long long i = st; i <= m; ++i) {
        ans &= a[i];
    }
    cout << ans << '\n';
    return 0;
}
