#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=2e6+10;
LL n,d,cnt,minn,e,a[N],vis[N];
void dfs(LL u,LL cur){
    if(cur>minn)return ;
    if(u==e){
        if(cur<minn){
            minn=cur;cnt=1;
        }
        else cnt++;
    }
    for(LL i=1;i<=n;i++){
        if(!vis[i]&&abs(a[u]-a[i]<=d)){
            vis[i]=1;
            dfs(i,cur+1);
            vis[i]=0;
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    LL c,T;
    scanf("%lld%lld",&c,&T);
    while(T--){
        LL ans=0;
        scanf("%lld%lld",&n,&d);
        for(LL i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        for(LL i=1;i<=n;i++){
            for(LL j=i+1;j<=n;j++){
                minn=0x7f7f7f7f7f7f7f7f;
                e=j;cnt=0;
                vis[i]=1;
                dfs(i,1);
                vis[i]=0;
                if(cnt==2)ans++;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
