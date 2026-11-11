#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <queue>
using namespace std;
using ui32 = unsigned int;
using big = long long;
using ui64 = unsigned big;
using bigf = long double;
constexpr const big INF = 1e18;
constexpr const big mod = 998244353;
constexpr const bigf EPS = 1e-8;

constexpr const int N = 5e5 +5;

big a[N], s[N], n, m;
bool check(int ans) {
    for(int i=ans;i<=n;i++) {
        if (a[i] * ans - (s[i] - s[i-ans]) <= m) return true;
    }
    return false;
}

void solve() {
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1, a+n+1);
    for(int i=1;i<=n;i++) s[i] = s[i-1]+a[i];
    int L = 1, R = n, ans = 0;
    while(L<=R) {
        int mid = (L+R)>>1;
        if(check(mid)) {
            ans = mid;
            L = mid+1;
        } else R = mid-1;
    }
    cout<<ans<<"\n";
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}
