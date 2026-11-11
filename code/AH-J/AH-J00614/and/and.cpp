#include <bits/stdc++.h>
using namespace std;
int n, m, a[300000], ans, cnt[6], d[30];
bool ok = true, ko = true;
inline void dfs(int x, int y, int z){
    if(x == m){
        ans = max(ans, y);
        return;
    }
    if(z >= n + 1){
        return;
    }
    if(x == 0){
        dfs(1, a[z], z + 1);
    }
    else{
        dfs(x + 1, y & a[z], z + 1);
    }
    dfs(x, y, z + 1);
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    d[0] = 1;
    for(int i = 1;i <= 20;i++){
        d[i] = d[i - 1] * 2;
    }
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(a[i] > 3){
            ok = false;
        }
        bool o = false;
        for(int j = 0;j <= 20;j++){
            if(a[i] == d[j] - 1){
                o = true;
                break;
            }
        }
        if(o == false){
            ko = false;
        }
    }
    if(ok == true){
        for(int i = 1;i <= n;i++){
            cnt[a[i]]++;
        }
        if(cnt[3] >= m){
            cout << 3;
        }
        else{
            if(cnt[3] + cnt[2] >= m){
                cout << 2;
            }
            else{
                if(cnt[3] + cnt[1] >= m){
                    cout << 1;
                }
                else{
                    cout << 0;
                }
            }
        }
        return 0;
    }
    if(ko == true){
        sort(a + 1, a + n + 1);
        cout << a[n - m + 1];
        return 0;
    }
    if(m == 1){
        sort(a + 1, a + n + 1);
        cout << a[n];
        return 0;
    }
    if(m == n){
        ans = a[1];
        for(int i = 2;i <= n;i++){
            ans &= a[i];
        }
        cout << ans;
        return 0;
    }
    if(m == 2){
        for(int i = 1;i <= n;i++){
            for(int j = i + 1;j <= n;j++){
                ans = max(ans, a[i] & a[j]);
            }
        }
        cout << ans;
        return 0;
    }
    dfs(0, 0, 1);
    cout << ans;
    return 0;
}

