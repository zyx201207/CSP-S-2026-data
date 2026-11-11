//GZ-S00094 中央民族大学附属中学贵阳学校 伍兴睿麟
#include<bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int mod=1e9+7;
ll qp(ll x,ll y){ll res=0;while(y){if(y&1) res=res*x%mod;x=x*x%mod;y/=2;}return res%mod;}
int c,n,m,D,q;
ll ww[500005];
vector<pair<int,ll>>tag[500005];
ll dis[505][505];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(dis,0x3f,sizeof dis);
    cin>>c>>n>>m>>D>>q;
    for(int i=1;i<=m;i++) cin>>ww[i];
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int u;
            ll w;
            cin>>u>>w;
            for(int s=0;s<tag[u].size();s++){
                int v=tag[u][s].fi;
                ll d=tag[u][s].se;
                dis[i][v]=min(dis[i][v],d+w);
                dis[v][i]=min(dis[v][i],d+w);
            }
            tag[u].push_back({i,w});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++) {
                dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int u,v;
        cin>>u>>v;
        ll ans=1e18;
        for(int s=0;s<tag[u].size();s++) {
            int u1=tag[u][s].fi;
            ll p1=tag[u][s].se;
            for(int s1=0;s1<tag[v].size();s1++) {
                int v1=tag[v][s1].fi;
                ll p2=tag[v][s1].se;
              //  cout<<u1<<" "<<v1<<" "<<p1<<" "<<p2<<" "<<dis[u1][v1]<<endl;
                ans=min(ans,dis[u1][v1]+p1+p2);
            }
        }
        cout<<ans+ww[u]+ww[v]<<endl;
    }
    return 0;
}
