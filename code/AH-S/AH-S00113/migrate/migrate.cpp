#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int MAXN = 2e6 + 100;
int c, T;
int n, ans;
ll d, a[MAXN];
map<PII, int> g;

bool cunzai(PII p) {
    if (g.find(p) == g.end()) return false;
    return g[p];
}

void solve() {
    cin >> n >> d;

    g.clear();
    ans = 0;

    for (int i=1; i<=n; i++) cin >> a[i];

    for (int i=1; i<=n; i++) {
        int x = lower_bound(a+1, a+i, a[i] - d) - a;
        for (int j=x; j<i; j++) {
            PII p = make_pair(j, i);
            g[p] = 1;
        }
        for (int j=x; j<i; j++) {
            PII p = make_pair(j, i);
            for (int k=j+1; k<i; k++) {
                PII q = make_pair(j, k);
                if (cunzai(q)) g[p]++;
            }
        }
    }

    for (const pair<PII, int> &p : g) {
        if (p.second == 2) ans++;
    }

    cout << ans << "\n";
}

int main() {

    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> c >> T;

    while (T--) solve();

    return 0;
}
