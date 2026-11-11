#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1 << 30;
const ll INF = 1ll << 60;

const int N = 5e5 + 3;

ll a[N], s[N];

int n;

ll m;

bool check (int x) {
    for (int i = x; i <= n; i++) if (1ll * (x - 1) * a[i] - (s[i - 1] - s[i - x]) <= m) return true;
    return false;
}

int main () {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf ("%d%lld", &n, &m);
    for (int i = 1; i <= n; i++) scanf ("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    int L = 0, R = n + 1;
    while (L + 1 < R) {
        int M = (L + R) / 2;
        if (check(M)) L = M;
        else R = M;
    }
    printf("%d\n", L);
}