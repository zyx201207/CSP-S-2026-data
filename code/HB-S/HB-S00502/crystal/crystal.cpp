#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int a[N], s[N];
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a+1, a+n+1); int ss = 0;
    for(int i = 1;i <= n;i++) s[i] = s[i-1] + a[i];
    for(int i = n;i >= 1;i--) {
        int L = 1, R = i, ans = 0; while(L <= R) {
            int mid = (L + R) >> 1;
            int need = a[i] * (i - mid + 1) - (s[i] - s[mid-1]);
            if(need <= m) ans = mid, R = mid - 1;
            else L = mid + 1;
        } ss = max(ss, i - ans + 1);
    } cout << ss << endl;
    return 0;
}