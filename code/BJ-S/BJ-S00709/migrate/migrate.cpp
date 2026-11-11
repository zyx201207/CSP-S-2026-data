#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d,x[2000006],dis[2000006],f[2000006],sum[2000006];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    if(c<=6){
        while(t--){
            scanf("%lld%lld",&n,&d);
            for(int i=1;i<=n;i++){
                scanf("%lld",&x[i]);
            }
            long long ans=0;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++)dis[j]=-1,f[j]=0;
                dis[i]=0,f[i]=1;
                long long last=i;
                for(int j=i+1;j<=n;j++){
                    if(x[j]-x[last]>d){
                        if(x[j]-x[j-1]<=d){
                            last=j-1;
                            dis[j]=dis[last]+1;
                        }
                        else break;
                    }
                    else dis[j]=dis[last]+1;
                }
                for(int j=i+1;j<=n;j++){
                    if(dis[j]==-1)break;
                    for(int k=j-1;k>=i;k--){
                        if(x[j]-x[k]>d)break;
                        if(dis[k]+1==dis[j]){
                            f[j]+=f[k];
                        }
                        if(f[j]>2)break;
                    }
                }
                for(int j=i+1;j<=n;j++){
                    if(f[j]==2)ans++;
                }
               
            }
            printf("%lld\n",ans);
        }
    }
    else if(c==11 || c==12){
        while(t--){
            scanf("%lld%lld",&n,&d);
            for(int i=1;i<=n;i++){
                scanf("%lld",&x[i]);
            }
            long long ans=0;
            for(int i=1;i<=1;i++){
                for(int j=1;j<=n;j++)dis[j]=-1,f[j]=0,sum[j]=0;
                    dis[i]=0,f[i]=1;
                    long long last=i;
                    for(int j=i+1;j<=n;j++){
                        if(x[j]-x[last]>d){
                            if(x[j]-x[j-1]<=d){
                                last=j-1;
                                dis[j]=dis[last]+1;
                            }
                            else break;
                        }
                        else dis[j]=dis[last]+1;
                    }
                    sum[i]=1;
                    long long st=i,ed=i;
                    for(long long j=i+1;j<=n;j++){
                        if(dis[j]==-1)break;
                        while((x[j]-x[st]>d || dis[st]+1<dis[j]) && st<j)st++;
                        while(dis[ed+1]+1==dis[j])ed++;
                        if(dis[st]+1==dis[j])f[j]+=sum[ed]-sum[st-1];
                        sum[j]=sum[j-1]+min(5*j,f[j]);
                    }
                    long long ji=0;
                    for(int j=i+1;j<=n;j++){
                        if(f[j]==2)ji++;
                        ans+=ji;
                    }
                }
                printf("%lld\n",ans);
            }
        
        return 0;
    }
    else{
        while(t--){
            scanf("%lld%lld",&n,&d);
            for(int i=1;i<=n;i++){
                scanf("%lld",&x[i]);
            }
            long long ans=0;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++)dis[j]=-1,f[j]=0,sum[j]=0;
                dis[i]=0,f[i]=1;
                long long last=i;
                for(int j=i+1;j<=n;j++){
                    if(x[j]-x[last]>d){
                        if(x[j]-x[j-1]<=d){
                            last=j-1;
                            dis[j]=dis[last]+1;
                        }
                        else break;
                    }
                    else dis[j]=dis[last]+1;
                }
                sum[i]=1;
                long long st=i,ed=i;
                for(long long j=i+1;j<=n;j++){
                    if(dis[j]==-1)break;
                    while((x[j]-x[st]>d || dis[st]+1<dis[j]) && st<j)st++;
                    while(dis[ed+1]+1==dis[j])ed++;
                    if(dis[st]+1==dis[j])f[j]+=sum[ed]-sum[st-1];
                    sum[j]=sum[j-1]+min(3*j,f[j]);
                }
                for(int j=i+1;j<=n;j++){
                    if(f[j]==2)ans++;
                }
            }
            printf("%lld\n",ans);
        }
        
    }
    return 0;
}