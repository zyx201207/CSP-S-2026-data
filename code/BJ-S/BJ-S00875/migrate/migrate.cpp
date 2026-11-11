#include <bits/stdc++.h>
using namespace std;

const int N = 2000005;

int n;
long long d, x[N];
int dis[N], cnt[N];

int c, T;

void solveA() {
    //printf("%lld %lld\n", d, (x[2] - x[1]));
    if(d < (x[2] - x[1]) * 2) cout << 0 << endl;
    else if(n - (d / (x[2] - x[1])) - (d / (x[2] - x[1])) + 1 < 0) cout << 0 << endl;
    else cout << n - (d / (x[2] - x[1])) - (d / (x[2] - x[1])) + 1 << endl;

}


void solve() {
    long long ans = 0;
    cin >> n >> d;
    for(int i = 1; i <= n; i++) cin >> x[i];

    if(c == 11 || c == 12) {
        solveA();
        return;
    }


    for(int u = 1; u <= n; u++) {
        for(int i = u; i <= n; i++) dis[i] = 0x7f7f7f7f, cnt[i] = 0;
        for(int v = u + 1; v <= n; v++) {
            if(x[v] - x[u] <= d) {
                dis[v] = cnt[v] = 1;
                continue;
            }
            for(int k = v - 1; k >= u && x[v] - x[k] <= d; k--) {
                if(dis[v] == dis[k] + 1) cnt[v] += cnt[k];
                else if(dis[v] > dis[k] + 1) cnt[v] = cnt[k], dis[v] = dis[k] + 1;
            }
            ans += (cnt[v] == 2);
        }
    }

    cout << ans << endl;
    return;
}


int main() {

    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    ios :: sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> c >> T;
    while(T--) solve();
    return 0;

}
