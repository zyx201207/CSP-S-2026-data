#include<iostream>
constexpr int maxn=2e6+5;
int c,T,n,qz[maxn],hz[maxn],f1[maxn],f2[maxn],tl[maxn],tr[maxn];
long long d,x[maxn];
int main(){
    std::freopen("migrate.in","r",stdin);
    std::freopen("migrate.out","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin>>c>>T;
    while(T--){
        std::cin>>n>>d;
        for(int i=1;i<=n;++i) std::cin>>x[i],qz[i]=hz[i]=f1[i]=f2[i]=0;
        for(int i=1,p=1;i<=n;++i){
            while(p<n&&x[p+1]<=x[i]+d) ++p;
            tr[i]=p;
        }
        for(int i=n,p=n;i;--i){
            while(p>1&&x[p-1]>=x[i]-d) --p;
            tl[i]=p;
        }
        for(int i=1;i<=n;++i){
            ++qz[i];int v=tr[i];
            if(v==i) continue;
            if(tl[v]==i) qz[v]+=qz[i];
            else ++qz[v];
            if(v>i+1){
                if(tl[v]==i&&tl[v-1]==i) f1[v]+=qz[i];
                else ++f1[v];
            }
        }
        for(int i=n;i;--i){
            ++hz[i];int v=tl[i];
            if(v==i) continue;
            if(tr[v]==i) hz[v]+=hz[i];
            else ++hz[v];
            if(v<i-1){
                if(tr[v]==i&&tr[v+1]==i) f2[v]+=hz[i];
                else ++f2[v];
            }
        }
        long long ans=0;
        for(int i=1;i<n;++i) ans+=(long long)f2[i]*f1[i+1];
        std::cout<<ans<<'\n';
    }
    return 0;
}