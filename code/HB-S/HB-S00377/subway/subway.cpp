#include<cstdio>
using namespace std;

long long w[500005];

long long a[1005][1005];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    for(int i=0;i<=1002;i++){
        for(int k=0;k<=1002;k++){
            if(i==k){
                continue;
            }
            a[i][k]=2e8;
        }
    }
    long long c,n,m,d,q;
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%lld",&w[i]);
    }
    long long pre_t=0;
    long long pre_sta=0;
    for(int i=1;i<=n;i++){
        long long k=0;
        scanf("%lld",&k);
        for(int i=1;i<=k;i++){
            long long sta=0,t=0;
            scanf("%lld%lld",&sta,&t);
            if(i==1){
                pre_t=t;
                pre_sta=sta;
            }
            else{
                a[pre_sta][sta]=t+pre_t;
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int k=1;k<=m;k++){
            for(int p=1;p<=m;p++){
                if(a[i][k]>a[i][p]+a[p][k]){
                    a[i][k]=a[i][p]+a[p][k];
                }
            }
        }
    }
    for(int i=1;i<=q;i++){
        int start=0,goal=0;
        scanf("%d%d",&start,&goal);
        long long ans=a[start][goal];
        ans+=w[start];
        ans+=w[goal];
        printf("%lld\n",ans);
    }
    return 0;
}
