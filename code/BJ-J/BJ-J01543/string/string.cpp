#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 5;
ll a[N];
char c[N];
int n;

int main() {
	freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    deque<ll> q;
    for (int i = 1; i <= n; i++) cin >> a[i] >> c[i], q.push_back(i);
    ll ans = 0;
    while (!q.empty()) {
        ll i = q.front(), j = q.back();
        if (i == j) break;
        if (c[i] != c[j]) ans += min(a[i], a[j]);
        if (a[i] > a[j]) a[i] -= a[j], q.pop_back();
        else if (a[i] < a[j]) a[j] -= a[i], q.pop_front();
        else q.pop_back(), q.pop_front();
    }   
    cout << ans;
    return 0;
}