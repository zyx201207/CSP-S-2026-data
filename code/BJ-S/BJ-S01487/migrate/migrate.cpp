#include<bits/stdc++.h>
using namespace std;
long long c, t, n, m, x, a[2000010];
void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    bool flag = 1;
    x = a[2] - a[1];
    for(int i = 3; i <= n; i++){
        if(a[i] - a[i - 1] != x) flag = 0;
    }
    if(flag){
        if(x > r){
            cout << 0 << '\n';
            return;
        }
        cout << '1' << '\n';
        return;
    }
    cout << 0 << '\n;
    return;
}
int main(){
    cin.tie(nullptr) -> sync_with_stdio(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", " w", stdout);
    cin >> c >> t;
    while(t--){
        solve();
    }
    return 0;
}
