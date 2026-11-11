#include<bits/stdc++.h>
using namespace std;

long long c, T, n, m, ans = 0, a[5010], dp[5010], vis[5010], tot = 0, vib[5010];

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin>>c>>T;
    while(T--){
        ans = 0;
        cin>>n>>m;
        for(int i = 1; i <= n; i++){
            cin>>a[i];
        }
        memset(vib, 0, sizeof(vib));
        for(int k = 1; k <= n; k++){
            memset(dp, 0x3f3f3f3f3f3f3f3f, sizeof(dp));
            memset(vis, 0, sizeof(dp));
            tot = 0;
            dp[k] = 0;
            for(int i = k; i <= n; i++){
                for(int j = i+1; j <= n; j++){
                    if(a[j]-a[i] <= m){
                        if(dp[j] <= dp[i]+1){
                            if(dp[j] > dp[i]+1){
                                dp[j] = dp[i]+1;
                                if(vis[j] == 2){
                                    tot--;
                                }
                                vis[j] = 0;
                            }
                            vis[j]++;
                            if(vis[j] == 2){
                                tot++;
                            }
                            if((vis[j]-1) == 2){
                                tot--;
                            }
                        }
                    }else{
                        break;
                    }
                }
            }
            ans += tot;
        }
        cout<<ans<<endl;
    }
    return 0;
}
