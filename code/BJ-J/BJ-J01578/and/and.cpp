#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N], f[N][35];
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int ans = 0, flag = 0;
    for (int j = 30; j >= 0; j--){
        int cnt = 0;
        for (int i = 1; i <= n; i++){
            if ((a[i] >> j & 1) && (f[i][j + 1] || !flag)) f[i][j] = 1, cnt++;
            else f[i][j] = 0;
        }
        if (cnt >= m) ans += (1 << j), flag = 1;
        else if (flag){
            cout << ans << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}
