#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 5e5 + 55, MAXM = 3e5 + 35;

int n, m;
int a[MAXN];
int pos[MAXM];
int nxt[MAXN];

int dp[MAXN];

int ans[MAXM];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = n; i; i--) {
        nxt[i] = pos[a[i]];
        pos[a[i]] = i;
    }
    for(int i = 1; i <= n; i++) {
        dp[i]++;
        if(nxt[i])dp[nxt[i]] += dp[i];
        else{
            dp[i + 1] += dp[i];
            ans[a[i]] = dp[i];
        }
    }
    for(int i = 1; i <= m; i++) {
        cout << ans[i] << " \n"[i == m];
    }
    return 0;
}
