#include<bits/stdc++.h>
#define ll long long
#define to1 g[i][j].first
#define to2 g[i][k].first
#define cst1 g[i][j].second
#define cst2 g[i][k].second
using namespace std;
ll c,n,m,d,q,k;
const ll N=5e5+5,F=505,INF=4e18;
ll to,cst,x,y;
ll w[N];
ll dis[F][F];
vector<pair<ll,ll> > g[N];
char opt;
inline ll read(){
    ll res=0;
    while(cin>>opt){
        if(opt==' ') return res;
        res=res*10+(opt-'0');
    }
}
int main(){

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    //c=read(),n=read(),m=read(),d=read(),q=read();
    cin>>c>>n>>m>>d>>q;
    //for(ll i=1;i<=m;i++) w[i]=read();
    for(ll i=1;i<=m;i++) cin>>w[i];
    for(ll i=1;i<=n;i++){
        cin>>k;
        for(ll j=1;j<=k;j++){
            cin>>to>>cst;
            g[to].push_back({i,cst});
        }
    }
    //cst{x[r],y[r])=dis[x[r],y[r]]+w[x[r]][+w[y[r]]
    //              =w[x[r]]+w[y[r]]+cst(x[r],x1)+dis[x1,x2]+cst(x2,y[r])
    for(ll i=1;i<=n;i++)
        for(ll j=1;j<=n;j++) dis[i][j]=INF;
    for(ll i=1;i<=n;i++) dis[i][i]=0;
    for(ll i=1;i<=m;i++){
        for(ll j=0;j<g[i].size();j++){
            for(ll k=0;k<g[i].size();k++){
                if(to1==to2) continue;
                dis[to1][to2]=dis[to2][to1]=min(dis[to1][to2],cst1+cst2);
            }
        }
    }
    //for(int i=1;i<=n;i++)
        //for(int j=1;j<=n;j++)
            //cout<<i<<"<->"<<j<<": "<<dis[i][j]<<"\n";
    for(ll k=1;k<=n;k++)
        for(ll i=1;i<=n;i++)
            for(ll j=1;j<=n;j++)
                dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
    //for(int i=1;i<=n;i++)
        //for(int j=1;j<=n;j++)
            //cout<<i<<"<->"<<j<<": "<<dis[i][j]<<"\n";
    for(ll i=1;i<=q;i++){
        cin>>x>>y;
        ll mindis=INF;
        for(ll l=0;l<g[x].size();l++){
            for(ll r=0;r<g[y].size();r++){
                ll a=g[x][l].first,b=g[y][r].first;
                ll c=g[x][l].second,d=g[y][r].second;
                mindis=min(mindis,w[x]+w[y]+c+d+dis[a][b]);
            }
        }
        cout<<mindis<<"\n";
    }
    return 0;

}
//v   w[v]
//n  ai1 ai2 aik
//aij tij

//zhantai                  ditiekou
//1~m

//O()
