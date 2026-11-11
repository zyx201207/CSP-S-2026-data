#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define LL __int128
#define pii pair < int , int >
#define mp(i, j) make_pair(i, j)

const int N = 5e5 + 5;
ll n, m, a[N];

void solvetask() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    int l = 1, ans = 1;
    ll res = m;
    for(int i = 2; i <= n; i++) {
        res = res - (i - l) * (a[i] - a[i - 1]);
        while(res < 0) res += (a[i] - a[l]), l ++;
        ans = max(ans, i - l + 1);
    }
    cout << ans << "\n";
    return;
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    int T = 1;
    while(T --) solvetask();
    return 0;
}