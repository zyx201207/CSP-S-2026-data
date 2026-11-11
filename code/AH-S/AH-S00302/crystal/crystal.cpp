#include<bits/stdc++.h>
#define int long long
#define For(i, n) for (int i = 1; i <= (n); ++i)
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define Rep(i, n) for (int i = (n); i >= 1; --i)
#define REP(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;

const int N = 5e5 + 1000;
int n, m, a[N], ans;

inline int mabs(int x) {return (x >= 0 ? x : -x);}

void solveBF() {
    For (i, n) {
        int cnt = 0, res = 0;
        Rep (j, i) {
            if (cnt + mabs(a[i] - a[j]) > m) break;
            cnt += mabs(a[i] - a[j]);
            res++;
        }
        ans = max(ans, res);
    }
    cout << ans << '\n';
}

bool isA() {
    For (i, n) if (a[i] != i) return 0;
    return 1;
}
void solveA() {
    int x = 1;
    while (x*(x+1)/2 <= m) ++x;
    cout << x << '\n';
}

bool isB() {
    For (i, n-1) if (a[i+1] - a[i] != a[2] - a[1]) return 0;
    return 1;
}
void solveB() {
    int cnt = 0;
    Rep (i, n) {
        if (cnt + a[n]-a[i] > m) break;
        cnt += a[n]-a[i];
        ans++;
    }
    cout << ans << '\n';
}

int d[N], s[N];
void solve() {
    For (i, n-1) d[i] = a[i+1] - a[i];
    For (i, n-1) s[i] = s[i-1] + d[i];
    int v;
    For (i, n-1) if (s[i] > m) {v = a[i]; break;}
    int p = upper_bound(a+1, a+n+1, v) - a - 1, cnt = 0;
    Rep (i, p) {
        if (cnt + a[p] - a[i] > m) break;
        cnt += a[p] - a[i];
        ans++;
    }
    cout << ans << '\n';
}

signed main() {
    freopen("crystal.in", "r", stdin); freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;
    For (i, n) cin >> a[i];
    sort(a+1, a+n+1);
    if (n <= 5000) solveBF();
    else if (isA()) solveA();
    else if (isB()) solveB();
    else solve();
    return 0;
}