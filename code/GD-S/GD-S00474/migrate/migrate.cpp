#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5005;
int c,t,n,d,x[N],dpmax[N][N],maxnum[N][N];

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i = 1;i<=n;i++) cin>>x[i];
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++) dpmax[i][j] = LLONG_MAX-100,maxnum[i][j] = 0;
            dpmax[i][i] = 0;
            maxnum[i][i] = 1;
        }
        for(int i = 1;i<=n;i++){
            int now_dis = x[i+1]-x[i];
            int j = i+1;
            while(j<=n && now_dis <= d){
                for(int k = 1;k<=i;k++){
                    if(dpmax[k][j] > 1+dpmax[k][i]){
                        dpmax[k][j] = 1+dpmax[k][i];
                        maxnum[k][j] = maxnum[k][i];
                    }else if(dpmax[k][j] == 1+dpmax[k][i]){
                        maxnum[k][j] += maxnum[k][i];
                    }
                }
                now_dis += x[j+1]-x[j];
                j++;
            }
        }
        int ans = 0;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++) if(maxnum[i][j] == 2) ans++;
        }
        cout<<ans<<'\n';
    }

    return 0;
}