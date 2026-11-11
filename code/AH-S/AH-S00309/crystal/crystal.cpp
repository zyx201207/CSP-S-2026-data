#include <bits/stdc++.h>
#define filename "crystal"
using namespace std;

#define upw(i, a, b) for(int i = (a); i <= (b); ++i)
#define dnw(i, a, b) for(int i = (a); i >= (b); --i)
#define inf 0x3f3f3f3f
#define Linf 0x3f3f3f3f3f3f3f3f

template<class T> bool vmax(T &a, const T &b) { return b > a ? (a = b, 1) : 0; }
template<class T> bool vmin(T &a, const T &b) { return b < a ? (a = b, 1) : 0; }

const int N = 5e5 + 5;

#define int long long

int n, m, a[N];

int sum[N];

void WaterM() {
    cin >> n >> m;
    upw(i, 1, n) scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);

    upw(i, 1, n) sum[i] = sum[i - 1] + a[i];
    int ans = 0;
    upw(i, 1, n) {
        int L = 1, R = i;
        while(L < R) {
            int mid = (L + R + 1) >> 1;
            if(mid * a[i] - (sum[i] - sum[i - mid]) <= m) L = mid;
            else R = mid - 1;
        }
        vmax(ans, L);
    }
    cout << ans << '\n';
}

signed main() {
    freopen(filename".in", "r", stdin);
    freopen(filename".out", "w", stdout);
    signed _ = 1;
    // scanf("%d", &_);
    upw(round, 1, _) WaterM();
    return 0;
}