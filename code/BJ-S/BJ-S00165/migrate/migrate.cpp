#include<bits/stdc++.h>
using namespace std;
int t,c,n,cnt[305][305],f[2000005];
long long d,x[2000005];
long long dis[305][305];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d %d",&c,&t);
    while(t--){
        scanf("%d %lld",&n,&d);
        bool flag=1;
        for(int i=1;i<=n;i++)scanf("%lld ",x+i);
        for(int i=3;i<=n;i++){
            if((x[i]-x[i-1])!=(x[i-1]-x[i-2])){
                flag=0;
                break;
            }
        }

        if(n<=300){
            int ans=0;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    dis[i][j]=2e18;
                    cnt[i][j]=0;
                }
            }
            for(int i=1;i<=n;i++)dis[i][i]=0;
            for(int i=1;i<n;i++)if(x[i+1]-x[i]<=d)dis[i][i+1]=dis[i+1][i]=1;
            for(int k=1;k<=n;k++){
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=n;j++){
                        if(dis[i][k]!=2e18&&dis[k][j]!=2e18&&i!=k&&k!=j){
                            long long t=dis[i][k]+dis[k][j];
                            //printf("%d\n",t);
                            dis[i][j]=min(dis[i][j],t);
                        }
                    }
                }
            }/*
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    printf("%d ",dis[i][j]);
                }
                puts("");
            }*/
            for(int k=1;k<=n;k++){
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=n;j++){
                        if(dis[i][j]==2e18||dis[i][k]==2e18||dis[k][j]==2e18||i==k||k==j)continue;
                        long long t=dis[i][k]+dis[k][j];
                        if(t==dis[i][j])cnt[i][j]++;
                    }
                }
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(cnt[i][j]==2){
                        ans++;
                    }
                }
            }
            printf("%d\n",ans/2);
        }
        else if(flag)printf("%d",n-2);
        else puts("1");
    }
    return 0;
}