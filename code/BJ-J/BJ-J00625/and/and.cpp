#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;
int n, m, mx, ans, used[N];
string bit[N];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin >> n >> m;
    for(int i = 1, x;i <= n;i++){
        cin >> x;
        while(x){
            if(x & 1) bit[i] = '1' + bit[i];
            else bit[i] = '0' + bit[i];
            x >>= 1;
        }
        mx = max(mx, (long long)(bit[i].size()));
    }
    for(int i = 1;i <= n;i++){
        while(bit[i].size() < mx) bit[i] = '0' + bit[i];
    }
//    for(int i = 1;i <= n;i++) cout << bit[i] << '\n';
    for(int i = 0;i < mx;i++){
        int cnt = 0;
        for(int j = 1;j <= n;j++){
            if(used[j]) continue;
            if(bit[j][i] == '1') cnt++;
//            cout << j << ' ' << bit[j][i] << ' ';
        }
        if(cnt >= m){
            ans += (1 << mx - i - 1);
            for(int j = 1;j <= n;j++){
                if(used[j]) continue;
                if(bit[j][i] == '0') used[j] = 1;
            }
        }
//        cout << ans << ' ' << cnt << '\n';
//        for(int j = 1;j <= n;j++) cout << used[j] << ' ';
//        cout << '\n';
    }
    cout << ans << '\n';
    return 0;
}
