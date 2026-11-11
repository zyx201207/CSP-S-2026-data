#include<bits/stdc++.h>
using namespace std;using LL=long long;
#define f(i,a,b) for(int i=(a),E##i=(b);i<=E##i;++i)
#define fr(i,a,b) for(int i=(a),E##i=(b);i>=E##i;--i)
#define fu(i,a,b) for(int i=(a),E##i=(b);i<E##i;++i)
constexpr LL LINF=2e18;
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
    vector<int>w(m+1);f(j,1,m)cin>>w[j];
    vector<vector<pair<int,int>>>g(m+1);
    f(i,1,n){
        int k;cin>>k;
        while(k--){
            int a,t;cin>>a>>t;
            g[a].emplace_back(i,t);
        }
    }
    vector<vector<LL>>dis(n+1,vector<LL>(n+1,LINF));
    f(j,1,m){
        for(auto[i1,t1]:g[j])for(auto[i2,t2]:g[j]){
            dis[i1][i2]=min<LL>(dis[i1][i2],t1+t2);
        }
    }
    f(i,1,n)dis[i][i]=0;
    f(k,1,n)f(i,1,n)f(j,1,n)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--){
        int x,y;cin>>x>>y;
        // cerr<<"x="<<x<<" y="<<y<<endl;
        LL ans=LINF;
        for(auto[ix,tx]:g[x])for(auto[iy,ty]:g[y]){
            // cerr<<ix<<' '<<iy<<' '<<dis[1][2]<<endl;
            ans=min(ans,w[x]+tx+dis[ix][iy]+ty+w[y]);
        }
        cout<<ans<<endl;
    }
}
//15:29