#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+5;
ll n, a[N], pq, ph, sumq=0, sumh=0, have=0, ans=0;
char c[N];
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
    }
    pq=1; ph=n; sumq=a[1]; sumh=a[n];
    while (pq < ph) {
        if (c[pq] != c[ph]) {
            ans += min(sumq, sumh)-have;
        }
        have = min(sumq, sumh);
        if (sumq <= sumh) {
            pq++;
            sumq += a[pq];
        } else {
            ph--;
            sumh += a[ph];
        }
    }
    cout << ans;
    return 0;
}
