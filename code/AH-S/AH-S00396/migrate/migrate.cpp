#include <iostream>
#define int long long
using namespace std;
const int N=2e6+5;
struct node{ int w,c; }dq[N];
int C,T,n,k,tl,tr;
int a[N],dis[N],cnt[N],f[N],ct[N];
int dp(int st){
    int res=0;
    tl=1,tr=0;
    dq[++tr]={0,1};
    f[st]=0,ct[st]=1;
    for(int l=st,r=st+1;r<=n;r++){
        while(a[r]-a[l]>k){
            dq[tl].c-=ct[l];
            if(dq[tl].c==0) tl++;
            l++;
        }
        f[r]=dq[tl].w+1;
        ct[r]=dq[tl].c;
        if(f[r]==dq[tr].w) dq[tr].c+=ct[r];
        else dq[++tr]={f[r],ct[r]};
        if(ct[r]==2) res++;
    }
    return res;
}

void solve(){
    int ans=0;
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++) ans+=dp(i);
    printf("%lld\n",ans);
}

void solveA(){
    int ans=0;
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    tl=1,tr=0;
    dq[++tr]={0,1};
    f[1]=0,ct[1]=1;
    for(int l=1,r=2;r<=n;r++){
        while(a[r]-a[l]>k){
            dq[tl].c-=ct[l];
            if(dq[tl].c==0) tl++;
            l++;
        }
        f[r]=dq[tl].w+1;
        ct[r]=dq[tl].c;
        if(f[r]==dq[tr].w) dq[tr].c+=ct[r];
        else dq[++tr]={f[r],ct[r]};
        if(ct[r]==2) ans+=n-r+1;
    }
    printf("%lld\n",ans);
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>C>>T;
    while(T--){
        if(C<=10) solve();
        else if(C<=12) solveA();
    }
    return 0;
}
