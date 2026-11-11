#include<bits/stdc++.h>
// #define int long long
#define ll long long
#define maxm 2000005
#define maxn 1005
#define msk cerr
#define mod 1000000007
#define inf 0x3f3f3f3f3f3f3f3fll
using namespace std;
namespace Sasuke{
    int cas,T,n;
    int nxt[maxm],L[maxm];
    ll a[maxm],m,ans;
    int f[maxm][3];//0,1,2那个特殊点：不存在/很后面了/就是上一个的方案数
    signed main(){
        ios::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        cin>>cas>>T;
        for(int ii=1;ii<=T;ii++){
            cin>>n>>m;a[n+1]=inf;
            for(int i=1;i<=n;i++)cin>>a[i];
            // if(ii==13){
            //     msk<<n<<" "<<m<<"\n";
            //     for(int i=1;i<=n;i++)msk<<a[i]<<" ";msk<<"\n";
            // }
            // msk<<"a:";for(int i=2;i<=n;i++)msk<<a[i]-a[i-1]<<" ";msk<<"\n";
            int p=1;
            for(int i=1;i<=n;i++){
                while(p<n&&a[p+1]-a[i]<=m)p++;
                nxt[i]=p;f[i][0]=f[i][1]=f[i][2]=0;
                // msk<<i<<"->"<<nxt[i]<<"\n";
            }
            for(int i=n;i>=1;i--){
                int l=nxt[i],r=nxt[l];
                if(l==r)continue;//一次就跳到n，因此一定不可能满足条件
                //i->l->r
                int x=l-1,p1=l,p2=l;
                if(x>i){
                    p1=max(l,nxt[x]);
                }
                x--;if(x>i){
                    p2=max(l,nxt[x]);
                }
                f[i][0]+=r-p1;f[i][2]+=p1-p2;
                if(p1==r){
                    if(p2<r)f[i][2]+=f[l][0];
                }else{
                    f[i][1]+=f[l][1];f[i][0]+=f[l][0];
                    if(p2<=r-2&&p1<=r-2)f[i][1]+=f[l][2];
                }
                ans+=f[i][1]+f[i][2];
                // msk<<i<<" ["<<l<<","<<r<<"]"<<" p2:"<<p2<<" p1:"<<p1<<" r:"<<r
                // <<":"<<f[i][0]<<" "<<f[i][1]<<" "<<f[i][2]<<"\n";
            }
            cout<<ans<<"\n";
            ans=0;
        }
        return 0;
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    // freopen("migrate1.in","r",stdin);
    freopen("migrate.out","w",stdout);
    freopen("ssk.err","w",stderr);
    Sasuke::main();
    msk<<"TIME:"<<clock()/1./CLOCKS_PER_SEC<<"\n";
    return 0;
}
/*
g++ -o migrate migrate.cpp -std=c++14 -Wall -Wl,--stack=200000000 -O2 & .\migrate   
*/