#include<bits/stdc++.h>
// #define int long long
#define ll long long
#define maxm 500005
#define maxn 1005
#define msk cerr
#define mod 1000000007
#define inf 0x3f3f3f3f3f3f3f3fll
#define Mn(x,y) (x=min(x,y))
using namespace std;
namespace Sasuke{
    int cas,T,N,n,m;
    ll ans;
    int a[maxm];
    struct edge{int x,w;};
    vector<edge>hv[maxm];
    ll f[maxn][maxn];
    signed main(){
        ios::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        cin>>cas>>n>>m>>N>>T;
        for(int i=1;i<=m;i++)cin>>a[i];
        for(int i=1;i<=n;i++){
            int len;cin>>len;
            for(int j=1;j<=len;j++){
                int x,w;cin>>x>>w;
                // e[i].push_back({x,w});
                hv[x].push_back({i,w});
            }
        }
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i^j)f[i][j]=inf;
        for(int i=1;i<=m;i++){
            for(int j=0;j<hv[i].size();j++)
                for(int k=j+1;k<hv[i].size();k++){
                    int u=hv[i][j].x,v=hv[i][k].x;
                    ll w=hv[i][j].w+hv[i][k].w;
                    // msk<<"mn:"<<u<<" "<<v<<" w:"<<w<<"\n";
                    Mn(f[u][v],w);Mn(f[v][u],w);
                }
        }
        for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
            Mn(f[i][j],f[i][k]+f[k][j]);
        for(int i=1;i<=T;i++){
            int x,y;cin>>x>>y;
            ans=inf;
            for(int j=0;j<hv[x].size();j++)
                for(int k=0;k<hv[y].size();k++)
                    Mn(ans,f[hv[x][j].x][hv[y][k].x]+hv[x][j].w+hv[y][k].w);
            // msk<<x<<" "<<y<<":"<<ans<<"\n";
            ans+=a[x]+a[y];
            cout<<ans<<"\n";
        }
        return 0;
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    // freopen("subway7.in","r",stdin);
    freopen("subway.out","w",stdout);
    freopen("ssk.err","w",stderr);
    Sasuke::main();//while(1);
    msk<<"TIME:"<<clock()/1./CLOCKS_PER_SEC<<"\n";
    return 0;
}
/*
g++ -o subway subway.cpp -std=c++14 -Wall -Wl,--stack=200000000 -O2 & .\subway   
*/