#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t,n;
ll x[2000005],d;
int way[305][305],ans,dp[305][305];
void dfs1(int fa,int a,int cnt){
    dp[fa][a]=min(cnt,dp[fa][a]);
    for(int i=a+1;i<=n;i++){
        if(x[i]-x[a]<=d){
            dfs1(fa,i,cnt+1);
        }
    }
}
int dfs2(int fa,int a,int cnt){
    for(int i=a+1;i<=n;i++){
        if(x[i]-x[a]<=d&&cnt+1==dp[fa][i]){
            way[fa][i]++;
            dfs2(fa,i,cnt+1);
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    if(c<=2){
        while(t--){
            ans=0;
            memset(dp,0x3f,sizeof(dp));
            memset(way,0,sizeof(way));
            scanf("%d%lld",&n,&d);
            for(int i=1;i<=n;i++){
                scanf("%lld",&x[i]);
                dp[i][i]=0;
            }
            for(int i=1;i<n;i++){
                if(x[i+1]-x[i]<=d){
                    dfs1(i,i,0);
                }
            }
            for(int i=1;i<n;i++){
                if(x[i+1]-x[i]<=d){
                    dfs2(i,i,0);
                }
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(way[i][j]==2){
                        ans++;
                    }
                }
            }
            printf("%d\n",ans);
        }
        return 0;
    }
    ll T;
    if(c>=11&&c<=12){
        while(t--){
            scanf("%d%lld",&n,&d);
            for(int i=1;i<=n;i++){
                scanf("%lld",&x[i]);
            }
            T=x[n]-x[n-1];
            ll a=d/T*2;
            if(n-a+1<0||a<=2)printf("0\n");
            else{
                printf("%lld\n",n-a+1);
            }
        }
    }
    return 0;
}
