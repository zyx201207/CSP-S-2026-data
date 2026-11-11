#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 1e6 + 10;
const int I = 1e18 + 10;
int n, m;
int a[N], s[N], s0[N];

struct node{
    int v, p, tl;
    
    bool operator < (const node &x) const {
        return v < x.v;
    } 
}b[N];

signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios :: sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    a[n + 1] = I;
    int cnt = 1, tp = 0;
    for (int i = 2; i <= n + 1; i++) {
        if (a[i] != a[i - 1]) b[++tp] = {a[i - 1], cnt, 0}, cnt = 1;
        else cnt++;
    }
    n = tp;
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++) {
        b[i].tl = b[i].v * b[i].p;
        s[i] = s[i - 1] + b[i].tl, s0[i] = s0[i - 1] + b[i].p;
    }
    int ans = b[1].p;
    for (int l = 1, r = 2; r <= n; r++) {
        while (l < r && b[r].v * (s0[r - 1] - s0[l]) - (s[r - 1] - s[l]) > m) l++;
        // cout << l << ' ' << r << '\n';
        // if (l == r) { ans = max(ans, b[r].p); continue; }
        int res = s0[r] - s0[l], k = m - (b[r].v * (s0[r - 1] - s0[l]) - (s[r - 1] - s[l]));
        res = res + min(b[l].p, (k / (b[r].v - b[l].v))), ans = max(ans, res);
        // cout << res << '\n';
    }
    cout << ans << '\n';
    return 0;
}

/*
g++ crystal.cpp -o1 -fsanitize=leak,address,undefined
./1
diff crystal.out crystal1.ans
*/