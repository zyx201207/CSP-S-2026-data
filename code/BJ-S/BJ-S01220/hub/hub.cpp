#include <bits/stdc++.h>
using namespace std;
long long c, t, n, k;
int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    while(t --){
        cin >> n >> k;
        long long u, v, c[150][150] = {0}, ans = 1e9;
        for(int i = 1;i <= n;i ++){
            for(int j = 1;j <= n;j ++){
                c[i][j] = 1e9;
            }
        }
        for(int i = 2;i <= n;i ++){
            cin >> u >> v;
            c[u][v] = 1;
            c[v][u] = 1;
        }
        for(int k = 1;k <= n;k ++){
            for(int i = 1;i <= n;i ++){
                for(int j = 1;j <= n;j ++){
                    if(c[i][k] + c[k][j] < c[i][j]){
                        c[i][j] = c[i][k] + c[k][j];
                    }
                }
            }
        }
        for(int i = 1;i <= 1 << n;i ++){
            long long num = i, l = 0, r = 1;
            vector<long long> nm;
            while(num){
                if(num & 1){
                    nm.push_back(r);
                    l ++;
                }
                r ++;
                num /= 2;
            }
            if(l == k){
                long long um = 0;
                for(int j = 0;j < nm.size();j ++){
                    long long mi = 1e9;
                    for(int k = 0;k < nm.size();k ++){
                        if(k == j)continue;
                        mi = min(mi, c[nm[j]][nm[k]]);
                    }
                    um = max(um, mi);
                }
                ans = min(ans, um);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
