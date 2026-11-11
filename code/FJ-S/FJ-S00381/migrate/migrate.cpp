#include<bits/stdc++.h>
using namespace std;
typedef long long i64;
const int N=2e6+5,M=5e3+5;
i64 c,t,n,D;
i64 a[N];
namespace n2log{
    const int INF=1e9;
    int d[M<<2],f[M<<2];
    void pu(int u){
        if(d[u<<1]<d[u<<1|1])d[u]=d[u<<1],f[u]=f[u<<1];
        else if(d[u<<1]>d[u<<1|1])d[u]=d[u<<1|1],f[u]=f[u<<1|1];
        else d[u]=d[u<<1],f[u]=min(3,f[u<<1]+f[u<<1|1]);
    }
    void bld(int u,int l,int r){
        if(l==r)return d[u]=INF,f[u]=0,void();
        int mid=(l+r)/2;
        bld(u<<1,l,mid);bld(u<<1|1,mid+1,r);
        pu(u);
    }
    void upd(int u,int l,int r,int x,int nd,int nf){
        if(l==r)return d[u]=nd,f[u]=nf,void();
        int mid=(l+r)/2;
        if(x<=mid)upd(u<<1,l,mid,x,nd,nf);
        else upd(u<<1|1,mid+1,r,x,nd,nf);
        pu(u);
    }
    void qry(int u,int l,int r,int L,int R,int& ansd,int& ansf){
        if(L<=l && r<=R){
            if(d[u]<ansd)ansd=d[u],ansf=f[u];
            else if(d[u]==ansd)ansf=min(3,ansf+f[u]);
            return;
        }
        int mid=(l+r)/2;
        if(L<=mid)qry(u<<1,l,mid,L,R,ansd,ansf);
        if(mid<R)qry(u<<1|1,mid+1,r,L,R,ansd,ansf);
    }
    void solve(){
        cin>>n>>D;
        for(int i=1;i<=n;i++)cin>>a[i];
        int ans=0;
        for(int l=1;l<=n;l++){
            bld(1,1,n),upd(1,1,n,l,0,1);
            int t=l;
            for(int r=l+1;r<=n;r++){
                while(t<r && a[t]<a[r]-D)t++;
                if(t==r)break;
                int ansd=INF,ansf=0;
                qry(1,1,n,t,r-1,ansd,ansf);
                //cerr<<"on: ("<<l<<','<<r<<") "<<ansf<<endl;
                if(ansf==2)ans++;
                upd(1,1,n,r,ansd+1,ansf);
            }
            
        }
        cout<<ans<<'\n';
    }
}
namespace traitA{
    void solve(){
        cin>>n>>D;
        for(int i=1;i<=n;i++)cin>>a[i];
        if(n==1)return cout<<0<<'\n',void();
        int x=D/(a[2]-a[1]);
        if(x<=1)cout<<0<<'\n';
        else cout<<max(0ll,n-2*x+1)<<'\n';
    }
}
namespace traitB{
    int lc[N];
    void solve(){
        cin>>n>>D;
        int ans=0;
        for(int i=1;i<=n;i++)cin>>a[i];
        if(n==1)return cout<<0<<'\n',void();
        int r=1,L=1,R=1;
        for(int l=1;l<=n;l++){
            while(R<n && a[R+1]-a[l]<=D)R++;
            while(r<n && (a[r]-a[l]<=D || R-L+1>2)){
                r++;
                while(L<n && a[r]-a[L]>D)L++;
            }
            if(a[r]-a[l]>D && R-L+1==2)lc[l]=r;
            else lc[l]=-1;
        }
        r=1,L=1,R=1;
        for(int l=1;l<=n;l++){
            while(R<n && a[R+1]-a[l]<=D)R++;
            while(r<=n && (a[r]-a[l]<=D || R-L+1>=2)){
                r++;
                while(L<n && a[r]-a[L]>D)L++;
            }
            if(lc[l]!=-1)ans+=r-lc[l];
        }
        cout<<ans<<'\n';
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--){
        if(c==11 || c==12)traitA::solve();
        else if(c==13 || c==14)traitB::solve();
        else n2log::solve();
    }
}