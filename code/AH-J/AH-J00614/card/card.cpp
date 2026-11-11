#include <bits/stdc++.h>
using namespace std;
int n, m, a[600000], z[600000], t, cnt[330000];
bool ok = true, b[330000];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(i != 1 && a[i] < a[i - 1]){
            ok = false;
        }
    }
    if(m == 1){
        cout << n;
        return 0;
    }
    if(m == 2){
        cnt[a[n]] = n;
        for(int i = 1;i <= n;i++){
            if(a[n] != a[i]){
                cnt[a[i]]++;
            }
        }
        cout << cnt[1] << ' ' << cnt[2];
        return 0;
    }
    if(ok == true){
        for(int i = n;i > 0;i--){
            if(i == n){
                cnt[a[i]] = n;
            }
            else{
                if(a[i] != a[i + 1]){
                    cnt[a[i]] = i;
                }
            }
        }
        for(int i = 1;i <= m;i++){
            cout << cnt[i] << ' ';
        }
        return 0;
    }
    for(int i = 1;i <= n;i++){
        t = 0;
        for(int j = 1;j <= m;j++){
            b[j] = false;
        }
        for(int j = i;j <= n;j++){
            for(int k = t;k > 0;k--){
                if(z[k] == a[j]){
                    t = k - 1;
                    break;
                }
            }
            z[++t] = a[j];
        }
        for(int j = 1;j <= t;j++){
            if(b[z[j]] == false){
                b[z[j]] = true;
                cnt[z[j]]++;
            }
        }
    }
    for(int i = 1;i <= m;i++){
        cout << cnt[i] << ' ';
    }
    return 0;
}

