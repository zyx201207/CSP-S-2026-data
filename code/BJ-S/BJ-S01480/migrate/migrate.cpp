#include<bits/stdc++.h>
#define int long long
using namespace std;
int x[5005], ans, num[5005];
int n, d;
void dfs(int l, int r, int pos, int cnt){
    if (pos == r){
        ans = min(ans, cnt);
        num[cnt]++;
    }
    int i = pos + 1;
    while (i <= r && x[i] - x[pos] <= d){
        dfs(l, r, i, cnt + 1);
        i++;
    }
}
signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int c, t; cin >> c >> t;
    while (t--){
        cin >> n >> d;
        int cnt = 0;
        for (int i = 1; i <= n; i++) cin >> x[i];
        for (int i = 1; i < n; i++){
            for (int j = i + 1; j <= n; j++){
                ans = LONG_LONG_MAX;
                memset(num, 0, sizeof(num));
                dfs(i, j, i, 0);
                if (ans != LONG_LONG_MAX && num[ans] == 2) cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
