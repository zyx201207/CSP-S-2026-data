#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;

int n;
long long m;

long long a[N];

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];

    sort(a + 1, a + n + 1);

    long long now = 0, ans = 0;
    for(long long l = 1, r = 1; r <= n; r++) {
        now += (r - l) * (a[r] - a[r - 1]);
        while(l < r && now > m) {
            now -= (a[r] - a[l++]);
        }

        ans = max(ans, r - l + 1);
    }

    cout << ans << '\n';
}