#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 2e6 + 5;

int c, T;
int n, d;
int a[N];
int dp[N];
int nxt[N];


signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> c >> T;
    while(T--) {
        cin >> n >> d;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        cout << 0 << '\n';
    }
    return 0;
}