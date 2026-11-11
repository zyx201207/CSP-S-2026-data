#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mxN = 6e5;
ll ai[mxN];
ll N, M;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> ai[i];
    sort(ai, ai + N);
    int ans = 0;
    int l = N - 1, r = N - 1;
    ll m = 0;
    while (l >= 0) {
        while (m + ai[r] - ai[l - 1] <= M && l >= 0) {
            m += ai[r] - ai[l - 1];
            --l;
        }
        ans = max(ans, r - l + 1);
        m -= (r - l) * (ai[r] - ai[r - 1]);
        --r;
    }
    cout << ans;
}
