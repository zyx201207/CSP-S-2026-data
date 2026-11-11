#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=2000005;
ll C,T,n,d,a[maxn],r[maxn];
ll vis[maxn],cnt[maxn];
struct node{
    ll x,w;
}q[maxn];
ll h,t;
void bfs(ll x){
    memset(cnt,0,sizeof(cnt));
    memset(vis,0x3f,sizeof(vis));
    vis[x]=0;
    h=0,t=0;
    q[0]={x,0};
    cnt[x]=1;
    while(h<=t){
        node dq=q[h];
        h++;
        for(ll i=dq.x+1;i<=n && i<r[dq.x];i++){
            if(vis[i]>=dq.w+1){
                if(vis[i]>dq.w+1){
                    vis[i]=dq.w+1;
                    cnt[i]=cnt[dq.x];
                    q[++t]={i,dq.w+1};
                }
                else{
                    cnt[i]+=cnt[dq.x];
                    //q[++t]={i,dq.w+1};
                }
            }
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&C,&T);
    while(T--){
        scanf("%lld%lld",&n,&d);
        for(ll i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        a[n+1]=a[n]+d+1;
        ll R=1,ans=0;
        for(ll i=1;i<=n;i++){
            while(R<=n+1 && a[R]-a[i]<=d) R++;
            r[i]=R;
            //cout<<R-1<<endl;
        }
        for(ll i=1;i<=n;i++){
            if(C==13 || C==14){
                if(r[i]-2>i)
                ans+=r[r[i]-2]-r[i];
                continue;
            }
            bfs(i);
            //cout<<i<<':';
            for(ll j=i+1;j<=n;j++){
                //cout<<cnt[j]<<' ';
                if(cnt[j]==2) ans++;
            }
            //cout<<endl;
        }
        printf("%lld\n",ans);
    }

    return 0;
}
