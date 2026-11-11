#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=306;
int c,t,n,d,x[N];
int dis[N][N],cnt[N][N];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        for(int i=1;i<=n;i++)cin >> x[i];
        if(c<=6){
            memset(dis,0x3f,sizeof dis);
            memset(cnt,0,sizeof cnt);
            for(int i=1;i<=n;i++){
                dis[i][i]=0;
                cnt[i][i]=1;
                for(int j=i;j<=n;j++){
                    if(x[j]-x[i]>d)break;
                    dis[i][j]=1;
                    cnt[i][j]=1;
                }
            }
            for(int k=1;k<=n;k++){
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=n;j++){
                        if(dis[i][j]==dis[i][k]+dis[k][j])cnt[i][j]+=cnt[i][k]*cnt[k][j];
                        else if(dis[i][j]>dis[i][k]+dis[k][j])dis[i][j]=dis[i][k]+dis[k][j],cnt[i][j]=cnt[i][k]*cnt[k][j];
                    }
                }
            }
            int ans=0;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(cnt[i][j]==2)ans++;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}
