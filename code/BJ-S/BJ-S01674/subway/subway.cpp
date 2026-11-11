#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define fir first
#define sec second
#define pii pair<int,int>
#define inf (1000'000'000'000'000'000ll)
#define mkp make_pair
using namespace std;
int c,n,m,d,q,a[500005][24],k[500005],vis[505];
ll w[500005],t[500005][24];
ll dis[505][505],res,l[505][505];
vector<pair<int,ll> >e[500005];
void dij(int st){
    memset(vis,0,sizeof vis);
    dis[st][st]=0;
    // int sz=
    for(int id=1;id<=n;id++){
        int u=0;
        ll mn=inf;
        for(int i=1;i<=n;i++)if(vis[i]==0&&dis[st][i]<mn)mn=dis[st][i],u=i;
        vis[u]=1;
        for(int i=1;i<=n;i++){
            if(dis[st][i]>dis[st][u]+l[u][i])
                dis[st][i]=dis[st][u]+l[u][i];
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=n;i++)dis[i][i]=0;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k,a;
        ll t;cin>>k;
        for(int j=1;j<=k;j++)cin>>a>>t,e[a].pb(mkp(i,t));
        // for(int x=1;x<=k[i];x++)
        //     for(int y=1;y<=k[i];y++)
        //         dis[a[i][x]][a[i][y]]=min(dis[a[i][x]][a[i][y]],
        //         t[i][x]+t[i][y]);
    }
    for(int i=1;i<=m;i++){
        for(auto x:e[i])for(auto y:e[i])
                dis[x.fir][y.fir]=min(dis[x.fir][y.fir],x.sec+y.sec);
    }
    // for(int i=1;i<=n;i++)
    //     for(int j=1;j<=n;j++)
    //         for(int k=1;k<=n;k++)
    //             dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    for(int i=1;i<=n;i++)   
        for(int j=1;j<=n;j++)l[i][j]=dis[i][j];
    memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=n;i++)dij(i);
    // for(int i=1;i<=n;i++)
    //     for(int j=1;j<=n;j++)
    //         cout<<i<<" "<<j<<":"<<dis[i][j]<<"\n";
    while(q--){
        int x,y;cin>>x>>y;
        res=inf;
        // for(int i=1;i<=k[x];i++)
        //     for(int j=1;j<=k[y];j++)
        for(auto i:e[x])for(auto j:e[y])
            res=min(res,i.sec+j.sec+dis[i.fir][j.fir]);
        cout<<res+w[x]+w[y]<<"\n";
    }
    return 0;
}