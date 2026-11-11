#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 5e5 +5;

int n, m, a[N], b[N], cnt, ans[N];

signed main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++){
        memset(b, 0, sizeof(b));
        cnt = 0;
        for(int j = i; j <= n; j++){
            int pos = -1;
            for(int k = 1; k <= cnt; k++){
                if(b[k] == a[j]){
                    pos = k;
                    break;
                }
            }
            if(pos == -1){
                b[++cnt] = a[j];
            } else {
                for(int k = pos; k <= cnt; k++) b[k] = 0;
                cnt = pos;
                b[cnt] = a[j];
            }
        }
        for(int j = 1; j <= cnt; j++){
            ans[b[j]]++;
        }
    }
    for(int i = 1; i <= m; i++) cout << ans[i] << ' ';
    return 0;
}
