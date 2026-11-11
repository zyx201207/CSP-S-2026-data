#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, a[200010], sum, pre[200010], ans;
char c[200010];

class Pair {
public: ll a; char c;
};

queue<Pair> q1, q2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    cin >> n;

    for (ll i = 1; i <= n; i++) cin >> a[i] >> c[i], sum += a[i], pre[i] = pre[i - 1] + a[i];

    ll pos = lower_bound(pre + 1, pre + n + 1, (sum + 1) / 2) - pre;

    for (ll i = 1; i < pos; i++) q1.push({a[i], c[i]});

    if (sum % 2 == 1) {
        if (pre[pos - 1] + 1 < (sum + 1) / 2) q1.push({(sum + 1) / 2 - 1 - pre[pos - 1], c[pos]});
    } else q1.push({(sum + 1) / 2 - pre[pos - 1], c[pos]});

    for (ll i = n; i > pos; i--) q2.push({a[i], c[i]});

    if (sum % 2 == 1) {
        if (pre[pos] > (sum + 1) / 2) q2.push({pre[pos] - (sum + 1) / 2, c[pos]});
    } else if (pre[pos] > sum / 2) q2.push({pre[pos] - sum / 2, c[pos]});

    while (!q1.empty() && !q2.empty()) {
        Pair & h1 = q1.front();
        Pair & h2 = q2.front();
        if (h1.c != h2.c) ans += min(h1.a, h2.a);
        if (h1.a > h2.a) h1.a -= h2.a, q2.pop();
        else if (h1.a < h2.a) h2.a -= h1.a, q1.pop();
        else q1.pop(), q2.pop();
    }

    cout << ans;

    return 0;
}
