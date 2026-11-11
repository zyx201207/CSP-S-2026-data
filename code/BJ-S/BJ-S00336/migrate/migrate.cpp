#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
namespace cod1{
    constexpr ll N=2e6+5,inf=1e18;
    ll n,d,x[N],r[N],mnd[N];
    ull cnt[N];
    mt19937 Rand(time(0));
    void init(){
        for(int i=1;i<=n;i++){
            x[i]=r[i]=mnd[i]=cnt[i]=0;
        }
    }
    struct seg{
        ll l,r;
    };
    void work(){
        init();
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n;i++){
            r[i]=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
            //cerr<<r[i]<<" ";
        }
       // cerr<<"\n";
        ull w=Rand();
        ll ans=0;
        for(int i=1;i<=n;i++){
            ll mxr=i;
            vector<seg> ve;
            ve.push_back({0,0});
            for(int j=i;j<=n;j++)mnd[j]=0;
            for(int ci=1;;ci++){
                ll to=r[mxr];
                if(to==mxr)break;
                for(int j=mxr+1;j<=to;j++){
                    mnd[j]=ci;
                }
                ve.push_back({mxr+1,to});
                mxr=to;
            }
            ve.push_back({inf,inf});
            for(int j=i;j<=mxr;j++){
                cnt[j]=0;
            }
            ll sum=0;cnt[i]=w;cnt[i+1]=-w;
            for(int j=i;j<=mxr;j++){
                sum+=cnt[j];
                ll le=j+1,ri=r[j];
                le=max(le,ve[mnd[j]+1].l);
                if(le<=ri){
                    cnt[le]+=sum;
                    cnt[ri+1]-=sum;
                    //cerr<<le<<" "<<ri<<" "<<sum<<"\n";
                }
                // if(sum==2){
                //     cerr<<i<<" "<<j<<"\n";
                // }
                ans+=(sum==w*2ull);
            }
        }
        cout<<ans<<"\n";
    }
}
namespace cod2{
    constexpr ll N=2e6+5,inf=1e18;
    ll n,d,x[N],r[N];
    mt19937 Rand(time(0));
    void init(){
        for(int i=1;i<=n;i++){
            x[i]=r[i]=0;
        }
    }
    struct seg{
        ll l,r;
    };
    void work(){
        init();
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n;i++){
            r[i]=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
        }
        ll p=r[1]-1;
        if(p>n/2 || p<=1){
            cout<<0<<"\n";
        }else{
            cout<<n-2*p+1<<"\n";
        }
    }
}
namespace cod3{
    void init(){
        
    }
    void work(){
        init();
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll Tid,Test;
    cin>>Tid>>Test;
    while(Test--){
        if(Tid<=10){
            cod1::work();
        }else if(Tid<=12){
            cod2::work();
        }else if(Tid<=14){
            cod1::work();
        }else{
            cod1::work();
        }
    }
    return 0;
}