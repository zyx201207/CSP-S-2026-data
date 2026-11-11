#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,ans;
int a[5005];
int mn[5005];
int dp[5005];
int x[5005];
bool flag;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--){
        memset(mn,0,sizeof mn);
        ans=0;
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
        for(int v=2;v<=n;v++){
            for(int u=1;u<v;u++){
                memset(dp,0,sizeof dp);
                memset(x,0,sizeof x);
                memset(mn,0,sizeof mn);
                mn[u]=0;
                flag=0;
                for(int i=u+1,j=u;i<=v;){
                    while(a[i]-a[j]<=d&&i<=v)mn[i]=mn[j]+1,i++;
                    j=i-1;
                    if(a[i]-a[j]>d&&i<=v){
                        flag=1;
                        break;
                    }
                }
                if(flag)continue;
                dp[u]=1;
                int tmp=u;
                x[0]=1;
                for(int i=u+1;i<=v;i++){
                    if(mn[i]==0)break;
                    for(;a[i]-a[tmp]>d;tmp++)x[mn[tmp]]-=dp[tmp];
                    dp[i]+=x[mn[i]-1];
                    x[mn[i]]+=dp[i];
                }
                if(dp[v]==2)ans++;
            }
        }
        printf("%lld\n",ans);
    }
}
