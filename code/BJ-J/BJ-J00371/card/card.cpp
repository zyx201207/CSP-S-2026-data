#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[500005];
int ans[300005];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> a[i];

    // n <= 5 m <= 2 12'
    if(n <= 5 && m <= 2){
        if(m == 1){
            cout << n;
            return 0;
        }
        for(int i = 1; i <= n; i ++){
            int cnt = 0, t[10] = {0};
            for(int j = i; j <= n; j ++){
                t[++cnt] = a[j];
                for(int k = cnt - 1; k >= 1; k --){
                    if(t[k] == t[j]){
                        cnt = k; break;
                    }
                }
            }
            for(int j = 1; j <= cnt; j ++) ans[t[j]] ++;
        }
        for(int i = 1; i <= m; i ++) cout << ans[i] << " ";
    }

    //A 16'
    for(int i = 1; i <= n; i ++){
        if(a[i + 1] == a[i]) continue;
        ans[a[i]] += i;
    }
    for(int i = 1; i <= m; i ++) cout << ans[i] << " ";
    return 0;
}
