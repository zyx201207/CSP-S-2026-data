#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 10, INF = 2e9;
int n, m, a[N], dp[31];
bitset <31> b[N];
bitset <N> vis, rvis;

signed main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n; i ++){
        cin >> a[i];
        for(int j = 0; a[i]; j ++){
            if(a[i] & 1){
                b[i][j] = 1;
                dp[j] ++;
            }
            a[i] /= 2;
        }
    }
    int ans = 0, t = 0;
    bool flag = 1;
    for(int j = 30; j >= 0; j --){
        if(dp[j] >= m){
            t = 0;
            for(int i = 1; i <= n; i ++){
                if(flag){
                    if(b[i][j]){
                        vis[i] = 1;
                        t ++;
                    }
                }
                else{
                    if(vis[i]){
                        if(b[i][j]){
                            t ++;
                        }
                        else{
                            rvis[i] = 1;
                        }
                    }
                }
            }
            if(t >= m){
                vis ^= rvis;
                rvis.reset();
                ans += 1 << j;
            }

            flag = 0;
        }
    }
    cout << ans << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
