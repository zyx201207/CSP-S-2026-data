#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=505,maxm=500005;
ll C,n,m,D,T,w[maxm];
struct node{
    ll id,t;
};
vector<node> stat[maxm];
ll g[maxn][maxn];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&C,&n,&m,&D,&T);
    for(ll i=1;i<=m;i++){
        scanf("%lld",&w[i]);
    }
    for(ll i=1;i<=n;i++){
        ll k,u,v;
        scanf("%lld",&k);
        for(ll j=1;j<=k;j++){
            scanf("%lld%lld",&u,&v);
            stat[u].push_back({i,v});
        }
    }
    memset(g,0x3f,sizeof(g));
    for(ll i=1;i<=n;i++){
        g[i][i]=0;
    }
    for(ll i=1;i<=m;i++){
        for(ll j=0;j<stat[i].size();j++){
            for(ll k=j+1;k<stat[i].size();k++){
                node x=stat[i][j],y=stat[i][k];
                g[x.id][y.id]=g[y.id][x.id]=min(g[x.id][y.id],x.t+y.t);
            }
        }
    }
    for(ll k=1;k<=n;k++){
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<g[i][j]<<' ';
        }
        cout<<endl;
    }*/
    while(T--){
        ll x,y,ans=LLONG_MAX;
        scanf("%lld%lld",&x,&y);
        for(ll i=0;i<stat[x].size();i++){
            for(ll j=0;j<stat[y].size();j++){
                node u=stat[x][i],v=stat[y][j];
                ans=min(ans,g[u.id][v.id]+u.t+v.t);
            }
        }
        printf("%lld\n",ans+w[x]+w[y]);
    }
    return 0;
}
