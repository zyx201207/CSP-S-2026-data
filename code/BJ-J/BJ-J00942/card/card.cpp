#include<bits/stdc++.h>
using namespace std;

int n, m, cnt, a[500010], b[500010], ans[500010];
bool flag, xza = true;

void solve(){
    int last[500010];
    for(int i = 1; i <= n; i++){
        last[a[i]] = i;
    }
    for(int i = 1; i <= m; i++){
        cout << last[i] << ' ';
    }
}

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] < a[i - 1]){
            xza = false;
        }
    }
    if(xza){
        solve();
        return 0;
    }
    for(int i = 1; i <= n; i++){
        cnt = 0;
        for(int j = i; j <= n; j++){
            flag = false;
            for(int k = 1; k <= cnt; k++){
                if(b[k] == a[j]){
                    cnt = k;
                    flag = true;
                    break;
                }
            }
            if(!flag){
                b[++cnt] = a[j];
            }
        }
        for(int j = 1; j <= cnt; j++){
            ans[b[j]]++;
        }
    }
    for(int i = 1; i <= m; i++){
        cout << ans[i] << ' ';
    }
    return 0;
}