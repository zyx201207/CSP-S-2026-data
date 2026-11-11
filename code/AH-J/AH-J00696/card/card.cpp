#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=1e5+10,INF=0x3f3f3f3f3f3f3f3f;
LL n,m,a[N],b[N],cnt[N],vis[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    LL f=1;
    for(LL i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(LL i=2;i<=n;i++) if(a[i]<a[i-1]) f=0;
    if(f){
        LL l=a[1],r=-1;
        for(LL i=2;i<=n;i++) r=max(a[i],r);
        for(LL i=1;i<=n;i++){
            l=max(l,a[i]);
            for(LL j=l;j<=r;j++) cnt[j]++;
        }
        for(LL i=1;i<=m;i++) cout<<cnt[i]<<" ";
        return 0;
    }
    for(LL i=1;i<=n;i++){
        memset(b,0,sizeof(b));
        memset(vis,0,sizeof(vis));
        LL R=1;
        b[R]=a[i];
        for(LL j=i+1;j<=n;j++){
            LL ok=0;
            for(LL x=1;x<=R;x++) if(b[x]==a[j]){ok=x;break;}
            if(ok) R=ok;
            else b[++R]=a[j];
        }
        for(LL j=1;j<=R;j++) vis[b[j]]++;
        for(LL j=1;j<=m;j++) if(vis[j]) cnt[j]++;
    }
    for(LL i=1;i<=m;i++) cout<<cnt[i]<<" ";
    return 0;
}
