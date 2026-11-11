#include<bits/stdc++.h>
using namespace std;
//#define int long long;
#define rep(x,y,z) for(register int x=y;x<=z;++x)
#define per(x,y,z) for(register int x=y;x>=z;--x)
#define endl '\n'
typedef long long ll;
const ll N=500005,INF=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q,w[N],a[25][N],b[25][N],t[N],k[N];
ll g[505][505];
void qry(int u,int v){
    ll ans=INF;
    rep(i,1,t[u]){
        rep(j,1,t[v]){
            if(g[a[i][u]][a[j][v]]==INF)continue;
            ans=min(ans,1LL*(b[i][u]+b[j][v]+g[a[i][u]][a[j][v]]));
        }
    }
    cout<<w[u]+w[v]+ans<<endl;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;//ok
    rep(i,1,m)cin>>w[i];//ok
    rep(i,1,n){
        cin>>k[i];
        rep(j,1,k[i]){
            int A,T;
            cin>>A>>T;
            a[++t[A]][A]=i,b[t[A]][A]=T;
        }
    }//ok
    rep(i,1,n)rep(j,1,n)g[i][j]=INF;//g[i][i]??????
    rep(i,1,n)g[i][i]=0;//ok
    rep(i,1,m)rep(j,1,t[i])rep(k,j+1,t[i]){
        g[a[j][i]][a[k][i]]=min(g[a[j][i]][a[k][i]],1LL*(b[j][i]+b[k][i]));
        g[a[k][i]][a[j][i]]=min(g[a[k][i]][a[j][i]],1LL*(b[k][i]+b[j][i]));

    }//ok
    rep(k,1,n)
    rep(i,1,n){
        if(g[i][k]==INF)continue;
        rep(j,1,n){
            if(g[k][j]==INF)continue;
            g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
        }
    }//ok||floyd i,j,k???
    rep(i,1,q){
        int x,y;
        cin>>x>>y;
        qry(x,y);
    }//ok
    return 0;
}//2h ac?