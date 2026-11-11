#include <bits/stdc++.h>
using namespace std;
long long C, T, n, d, f[2000005], ans[2000005];
long long x[2000005], cnt;
void dp(int u){
    memset(f, 0x3f, sizeof f);
    f[u] = 0;
    for (int i = u + 1; i <= n; i++){
        for (int j = u; j < i; j++){
            if (x[i] - x[j] > d) continue;
            if (f[j] + 1 < f[i]){
                ans[i] = 1;
                f[i] = f[j] + 1;
            }
            else if (f[j] + 1 == f[i]) ans[i]++;
        }
    }
//    for (int i = u + 1; i <= n; i++) cout << f[i] << " ";
//    cout << "---\n";
    for (int i = u + 1; i <= n; i++){
        if (ans[i] == 2) cnt++;
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> C >> T;
    while(T--){
        cnt = 0;
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> x[i];
        for (int i = 1; i <= n; i++) dp(i);
        cout << cnt << "\n";
    }
    return 0;
}
