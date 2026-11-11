#include<bits/stdc++.h>
#define int long long
#define For(i, n)for (int i = 1; i <= (n); ++i)
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define Rep(i, n) for (int i = (n); i >= 1; --i)
#define REP(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;

const int N = 2e5 + 1000, INF = 1e8;
int n, a[N], l[N], r[N], L; 
char c[N];

void solve() {
    string str = " ";
    For (i, n) str += c[i];
    int mid = (n+1)/2, cnt = 0;
    For (i, mid) if (str[i] != str[n+1-i]) cnt++;
    cout << cnt * *max_element(a+1, a+n+1);
}

signed main() {
    freopen("string.in", "r", stdin); freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n; string s = " ";
    For (i, n) {
        cin >> a[i] >> c[i];
        L += a[i];
        l[i] = r[i-1]+1, r[i] = r[i-1]+a[i];
    }
    // For (i, n) cout << c[i] << ": " << l[i] << ' ' << r[i] << '\n';
    if (L < INF) {
        For (i, n) For (j, a[i]) s += c[i];
        int mid = (L+1) / 2, cnt = 0;
        // cout << s << '\n';
        For (i, mid) {
            if (s[i] != s[L+1-i]) cnt++;
        }
        cout << cnt << '\n';
    }
    else solve();
    return 0;
}