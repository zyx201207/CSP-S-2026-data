#include <bits/stdc++.h>
using namespace std;
#define il inline
#define ll long long 
#define pii pair<int,ll>
#define fi first 
#define se second 
#define pb push_back
//remember to check the memory
const int N=5e5+5,M=505;
int n,m,d,q;
ll ans[M][M],w[N];
vector<pii>in[N];
signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int cid;cin>>cid>>m>>n>>d>>q;for(int i=1;i<=n;i++){cin>>w[i];}
    for(int i=1;i<=m;i++) {
        int k,x,tt,lst;cin>>k;
        for(int j=1;j<=k;j++) {
            cin>>x>>tt;
            in[x].pb(make_pair(i,tt));
        }
    }
    for(int i=1;i<=m;i++)for(int j=1;j<=m;j++)ans[i][j]=(i==j?0:3e18);
    for(int i=1;i<=n;i++) {
        for(int j=0;j<in[i].size();j++) {
            pii now=in[i][j];
            for(int k=0;k<in[i].size();k++) {
                if(in[i][j].fi==in[i][k].fi)continue;
                int u=in[i][j].fi,v=in[i][k].fi;
                // cout<<u<<' '<<v<<' '<<(ll)in[i][j].se+(ll)in[i][k].se<<'\n';
                ans[u][v]=min(ans[u][v],(ll)in[i][j].se+(ll)in[i][k].se);
                // add(in[i][j].fi,in[i][k].fi,in[i][j].se+in[i][k].se);
            }
        }
    }
    for(int k=1;k<=m;k++)for(int i=1;i<=m;i++)for(int j=1;j<=m;j++)ans[i][j]=min(ans[i][j],ans[i][k]+ans[k][j]);
    // for(int i=1;i<=m;i++) {
    //     for(int j=1;j<=m;j++) {
    //         cout<<ans[i][j]<<' ';
    //     }cout<<'\n';
    // }
    for(int i=1,u,v;i<=q;i++) {
        cin>>u>>v;ll res=3e18;
        for(int j=0;j<in[u].size();j++) {
            for(int k=0;k<in[v].size();k++) {
                int x=in[u][j].fi,y=in[v][k].fi;
                res=min(res,w[u]+w[v]+in[u][j].se+in[v][k].se+ans[x][y]);
            }
        }cout<<res<<'\n';
    }
    return 0;
}