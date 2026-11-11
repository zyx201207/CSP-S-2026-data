#include<bits/stdc++.h>
using namespace std;
namespace mycode{
    typedef long long ll;
    int n;ll d;
    ll x[2000005];
    int px[2000005];
    int nx[2000005];
    int fp[2000005];
    int fn[2000005];
    ll ans;
    void solve(){
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        int l=1;
        for(int i=2;i<=n;i++){while(l<i && x[i]-x[l]>d){l++;}px[i]=l;}
        l=n;
        for(int i=n-1;i>=1;i--){while(l>i && x[l]-x[i]>d){l--;}nx[i]=l;}
        fp[1]=1;
        for(int i=2;i<=n;i++){
            if(nx[px[i]]==i) fp[i]=fp[px[i]]+1;
            else fp[i]=1;
            if(i==n) fp[i]+=i-px[i]-1;
            else fp[i]+=max(0,px[i+1]-px[i]-1);
        }
        fn[n]=1;
        for(int i=n-1;i>=1;i--){
            if(px[nx[i]]==i) fn[i]=fn[nx[i]]+1;
            else fn[i]=1;
            if(i==1) fn[i]+=nx[i]-i-1;
            else fn[i]+=max(0,nx[i]-nx[i-1]-1);
        }
        // for(int i=1;i<=n;i++){printf("%d ",px[i]);}printf("\n");
        // for(int i=1;i<=n;i++){printf("%d ",nx[i]);}printf("\n");
        // for(int i=1;i<=n;i++){printf("%d ",fp[i]);}printf("\n");
        // for(int i=1;i<=n;i++){printf("%d ",fn[i]);}printf("\n");
        for(int i=2;i<=n-2;i++){
            int lv=0,rv=0;
            if(nx[px[i]]==i+1) lv+=fp[px[i]];
            if(px[nx[i+1]]==i) rv+=fn[nx[i+1]];
            lv+=max(0,min(i,px[i+2])-max(px[i+1],px[i]+1));
            rv+=max(0,min(nx[i],nx[i+1]-1)-max(nx[i-1],i+1));
            ans+=((ll)lv)*rv;
        }
        printf("%lld\n",ans);
    }
    void clear(){
        ans=0;
        for(int i=1;i<=n;i++) px[i]=nx[i]=fp[i]=fn[i]=0;
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,t;cin>>c>>t;
    while(t--){mycode::solve();mycode::clear();}
    return 0;
}