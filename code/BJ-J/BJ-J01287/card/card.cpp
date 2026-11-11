#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10, maxm = 3e5 + 10;
int n, m, a[maxn], now[maxm], nxt[maxn], ans[maxm];
bool vis[maxn];
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = n; i >= 1; i--) {
        nxt[i] = now[a[i]];
        now[a[i]] = i;
    }
    for(int i = 1; i <= n; i++) {
        if(vis[i]) continue;
        int cnt = 0;
        for(int j = i; j <= n; j++) {
            if(!vis[j]) {
                vis[j] = 1;
                cnt++;
            }
            while(nxt[j]) {
                j = nxt[j];
                if(!vis[j]) {
                    vis[j] = 1;
                    cnt++;
                }
            }
            ans[a[j]] += cnt;
        }
    }
    for(int i = 1; i <= m; i++) cout << ans[i] << " ";
    cout << "\n";
    return 0;
}