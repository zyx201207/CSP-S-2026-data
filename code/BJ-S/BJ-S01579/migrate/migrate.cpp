#include<bits/stdc++.h>
using namespace std;
vector<int> a[2000010];
long long b[2000010], cnt[2000010], cnt1[2000010], ans, n, d;
void dfs(int x){
    cnt[x] = 1;
    for (int _ = 1; _ <= n; _++){
        for (int i = 1; i <= n; i++){
            if (cnt[i]){
                for (auto y : a[i]){
                    cnt1[y] += cnt[i];
                }
            }
        }
        bool f = 1;
        for (int i = 1; i <= n; i++){
            if (!cnt[i] && cnt1[i] == 2){
                // cout << x << ' ' << i << endl;
                ans++;
            }
            cnt[i] = cnt1[i];
            if (!cnt[i]) f = 0;
        }
        if (f) break;
    }
}
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c, t;
    cin >> c >> t;
    while (t--){
        cin >> n >> d;
        for (int i = 1; i <= n; i++){
            cin >> b[i];
        }
        if (c == 11 || c == 12){
            if ((b[2]-b[1])*2 > d){
                cout << 0 << "\n";
                continue;
            }
            long long x = d/(b[2]-b[1]);
            cout << max(n-(x*2-1), 0ll) << "\n";
            continue;
        }
        for (int i = 1; i <= n; i++){
            for (int j = i+1; j <= n; j++){
                if (b[j]-b[i] <= d){
                    a[i].push_back(j);
                }
                else break;
            }
        }
        ans = 0;
        for (int i = 1; i <= n; i++){
            for (int i = 1; i <= n; i++) cnt[i] = cnt1[i] = 0;
            dfs(i);
        }
        cout << ans << "\n";
        for (int i = 1; i <= n; i++) a[i].clear();
    }
    return 0;
}
