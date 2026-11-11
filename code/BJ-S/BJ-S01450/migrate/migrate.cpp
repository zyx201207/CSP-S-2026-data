#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
const int N=2e6+5;
const int M=5e3+5;
int c,T,n,dis[M][M];
ll a[N],d,dp[M][M],pre[M][M],cnt;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&T);
    while(T--){
        scanf("%d%lld",&n,&d);cnt=0;
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        memset(pre,0,sizeof(pre));
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(i==j) dis[i][j]=1;
                else if(a[j]-a[i]<=d) dis[i][j]=2;
                else dis[i][j]=n+1;
            }
        }
        for(int i=1;i<=n;i++){
            dp[i][i]=1,pre[i][i]=1;
            if(dis[i][i+1]==2) dp[i][i+1]=1,pre[i][i+1]=2;
        }
        for(int i=1;i<=n;i++){
            for(int j=i+2;j<=n;j++){
                int la=max(i,(int)(lower_bound(a+1,a+n+1,a[j]-d)-a));
                dis[i][j]=dis[i][la]+1;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+2;j<=n;j++){
                int la=max(i,(int)(lower_bound(a+1,a+n+1,a[j]-d)-a));
                int ladis=lower_bound(dis[i]+la,dis[i]+j+1,dis[i][j])-dis[i]-1;
                dp[i][j]=pre[i][ladis]-pre[i][la-1];
                pre[i][j]=pre[i][j-1]+dp[i][j];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(dp[i][j]==2) cnt++;
            }
        }
        printf("%lld\n",cnt);
    }
    return 0;
}
