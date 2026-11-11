#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,n,L[2000010],R[2000010],nxt[2000010],pre[2000010];
long long dppre[2000010],dpnxt[2000010];
long long d,a[2000010],ans;
// int mst_fr(int x){
//     int L=x,R=n,res=x;
//     while(L<=R){
//         int mid=(L+R)>>1;
//         if(a[mid]-a[x]<=d){
//             L=mid+1;
//             res=mid;
//         }else{
//             R=mid-1;
//         }
//     }
//     return res;
// }
int find_fst_geq_k(long long k){
    if(a[n]<k){
        return n+1;
    }
    int L=1,R=n,res=n;
    while(L<=R){
        int mid=(L+R)>>1;
        if(a[mid]>=k){
            R=mid-1;
            res=mid;
        }else{
            L=mid+1;
        }
    }
    return res;
}
void solve(){
    scanf("%d%lld",&n,&d);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    if(n<=3){
        printf("0\n");
        return;
    }
    if(a[n]-a[1]<=d){
        printf("0\n");
        return;
    }
    ans=0;
    for(int i=1;i<=n;i++){
        nxt[i]=find_fst_geq_k(a[i]+d+1)-1;
        pre[i]=find_fst_geq_k(a[i]-d);
    }
    // for(int i=1;i<=n;i++){
    //     printf("pre:%d nxt:%d\n",pre[i],nxt[i]);
    // }
    int ll=1,rr=0;
    for(int i=1;i<=n;i++){
        dppre[i]=1;
        while(rr<n&&rr+1<i&&i==nxt[rr+1]){
            rr++;
            dppre[i]+=dppre[rr];
        }
        ll=rr+1;
    }
    ll=n+1,rr=n;
    for(int i=n;i>=1;i--){
        dpnxt[i]=1;
        while(ll>1&&ll-1>i&&i==pre[ll-1]){
            ll--;
            dpnxt[i]+=dpnxt[ll];
        }
        rr=ll-1;
    }
    // for(int i=1;i<=n;i++){
    //     printf("i=%d dpp:%d dpn:%d\n",i,dppre[i],dpnxt[i]);
    // }
    for(int i=1;i<=n-2;i++){
        if(nxt[i]<i+2){
            continue;
        }
        int k=nxt[i];
        int lf=a[k-2]+d+1,rt=a[k-1]+d;
        //a_R\in [lf,rt]
        R[i]=find_fst_geq_k(rt+1)-1;
        L[i]=find_fst_geq_k(lf);
        //R\in [L[i],R[i]]
        if(L[i]>R[i]){
            continue;
        }
        int xs1=1;
        if(pre[k-1]==i){
            xs1=dppre[i];
        }
        int xs2=(R[i]-L[i]+1);
        if(nxt[k]==R[i]){
            xs2+=dpnxt[R[i]]-1;
        }
        ans+=xs1*xs2;
        // printf("L=%d: [%d %d] add %d*%d\n",i,L[i],R[i],xs1,xs2);
    }
    printf("%lld\n",ans);
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&T,&T);
    for(int i=1;i<=T;i++){
        solve();
    }
    return 0;
}