#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <vector>
typedef unsigned char uchar;
typedef unsigned int uint;
typedef long long longlong;
typedef unsigned long long ulonglong;
typedef long double ldouble;
#define int longlong
#define uint ulonglong
#define double ldouble
using namespace std;

const int N = 2e6 + 5;
int n, d;
int a[N], sl[N], sr[N];

inline int gr(int x){ // >
    return upper_bound(a + 1, a + n + 1, x) - a;
}

inline int ge(int x){ // >=
    return lower_bound(a + 1, a + n + 1, x) - a;
}

inline int ls(int x){ // <
    return ge(x) - 1;
}

inline int le(int x){ // <=
    return gr(x) - 1;
}

inline int len(int l, int r){
    return r - l + 1;
}

inline void solve(int t){
    cin >> n >> d;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i < n; i++){
        int l = ge(a[i] - d), r = ls(a[i + 1] - d);
        sl[i] = len(l, r) <= 0 ? 0 : len(l, r) + sl[l];
    }
    sl[n] = 0;
    for (int i = n; i >= 2; i--){
        int l = gr(a[i - 1] + d), r = le(a[i] + d);
        sr[i] = len(l, r) <= 0 ? 0 : len(l, r) + sr[r];
    }
    sr[1] = 0;
    int ans = 0;
    a[0] = -4e18, a[n + 1] = 4e18;
    for (int x = 1; x < n; x++){
        int y = x + 1;
        int l = gr(a[x - 1] + d), r = le(a[x] + d);
        if (len(l, r) <= 0){
            continue;
        }
        int j = r;
        if (j <= y){
            continue;
        }
        int mr = len(l, r) + sr[j];
        l = ge(a[y] - d), r = ls(a[y + 1] - d);
        if (len(l, r) <= 0){
            continue;
        }
        int i = l;
        if (i >= x){
            continue;
        }
        int ml = len(l, r) + sl[i];
        if (t == 11){
            // cout << i << " " << x << " " << y << " " << j << " " << ml << " " << mr << "\n";
        }
        ans += ml * mr;
    }
    cout << ans << "\n";
}

signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int c, t; cin >> c >> t;
    while (t--){
        solve(t);
    }
    return 0;
}