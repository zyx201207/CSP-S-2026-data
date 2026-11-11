#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[500010], cnt[1010][1010], ans[300010];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        cnt[i][a[i]]++;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if((cnt[n][j]-cnt[i-1][j])%2 != 0){
                ans[j]++;
            }
        }
    }
    for(int i = 1; i <= m; i++){
        cout << ans[i] << " ";
    }
    return 0;
}
