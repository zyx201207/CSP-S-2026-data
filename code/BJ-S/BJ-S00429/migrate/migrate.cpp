#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int c,T;
int n;
long long d;
long long a[N];
struct wsw{
    int w;
    long long pl;
}dp[N][N];
long long dis[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&T);
    while(T--){
        if(c==11 || c==12){
            scanf("%d%lld",&n,&d);
            for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
            long long ans=0;
            for(int i=1;i<=1;i++){
                for(int j=0;j<N;j++) dis[j]=0;
                int l=i;
                dp[i][i]={0,1};
                dis[0]++;
                for(int j=i+1;j<=n;j++){
                    while(l<j&&a[j]-a[l]>d){
                        dis[dp[i][l].w]-=dp[i][l].pl;
                        l++;
                    }
                    if(l==j) break;
                    dp[i][j].w=dp[i][l].w+1;
                    dp[i][j].pl=dis[dp[i][l].w];
                    if(dp[i][j].pl==2) ans+=(n-j+1);
                    dis[dp[i][j].w]+=dp[i][j].pl;
                }
            }
            printf("%lld\n",ans);
            continue;
        }
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        long long ans=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<N;j++) dis[j]=0;
            int l=i;
            dp[i][i]={0,1};
            dis[0]++;
            for(int j=i+1;j<=n;j++){
                while(l<j&&a[j]-a[l]>d){
                    dis[dp[i][l].w]-=dp[i][l].pl;
                    l++;
                }
                if(l==j) break;
                dp[i][j].w=dp[i][l].w+1;
                dp[i][j].pl=dis[dp[i][l].w];
                if(dp[i][j].pl==2) ans++;
                dis[dp[i][j].w]+=dp[i][j].pl;
            }
        }
        printf("%lld\n",ans);
    }
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}