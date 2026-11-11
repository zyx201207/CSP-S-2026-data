#include<bits/stdc++.h>
using namespace std;
const int N=5005;
long long c,t;
long long n,d;
long long lis[N];
struct nod{
    long long cnt,num;
}dp[N][N];
long long cnt;
long long qu[N],low,top;
long long sum[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    for(long long tt=1;tt<=t;tt++){
        scanf("%lld%lld",&n,&d);
        for(long long i=1;i<=n;i++){
            scanf("%lld",&lis[i]);
        }
        for(long long i=1;i<=n;i++){
            for(long long j=i+1;j<=n;j++){
                dp[i][j].cnt=n*10;
            }
        }
        cnt=0;
        for(long long i=1;i<=n;i++){
            low=1;
            top=0;
            qu[++top]=i;
            sum[0]++;
            //printf("!!!!!");
            //for(long long t=0;t<=n-1;t++){
            //    printf("%lld ",sum[t]);
            //}
            //printf("\n");
            for(long long j=i+1;j<=n;j++){
                for(;low<=top&&lis[j]-lis[qu[low]]>d;low++){
                    sum[dp[i][qu[low]].cnt]--;
                }
                //if(i==3){
                //    for(long long t=0;t<=n-1;t++){
                //        printf("%lld ",sum[t]);
                //    }
                //    printf("\n");
                //}
                if(low<=top){
                    dp[i][j].cnt=dp[i][qu[low]].cnt+1;
                    dp[i][j].num=sum[dp[i][qu[low]].cnt];
                }
                if(dp[i][j].num==2){
                    cnt++;
                }
                if(dp[i][j].num>2){
                    for(long long t=dp[i][qu[low]].cnt;t<=dp[i][qu[top]].cnt;t++){
                        sum[t]=0;
                    }
                    break;
                }
                qu[++top]=j;
                sum[dp[i][qu[top]].cnt]++;
            }
            for(long long t=dp[i][qu[low]].cnt;t<=dp[i][qu[top]].cnt;t++){
                sum[t]=0;
            }
        }
        //for(long long i=1;i<=n;i++){
        //    for(long long j=1;j<=n;j++){
        //        printf("%lld ",dp[i][j].num);
        //    }
        //    printf("\n");
        //}
        printf("%lld\n",cnt);
    }
    return 0;
}


