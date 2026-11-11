#include <bits/stdc++.h>
#define ll long long
#define sz(a) (int)(a).size()
#define mk make_pair
#define pb push_back
#define fir first
#define sec second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define req(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
/*
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return x*f;
}
*/
const int N=505;
const int M=1e5+5;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll c,n,m,d,q,w[M],k[N],dis[N][N];
vector<pair<ll,ll> >e[M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    rep(i,1,m){
        cin>>w[i];
    }
    rep(i,1,n){
        cin>>k[i];
        rep(j,1,k[i]){
            ll a,t;
            cin>>a>>t;
            e[i].pb({a,t});
            //mp[i][a]=t;
        }
    }
    memset(dis,0x3f,sizeof dis);
    rep(i,1,m){
            rep(j,1,m) if(i==j) dis[i][j]=0;
        }
    rep(i,1,n){
        rep(j,0,sz(e[i])-1){
            rep(k,0,sz(e[i])-1){
                if(j==k) continue;
                ll u=e[i][j].fir,v=e[i][k].fir,w=e[i][j].sec+e[i][k].sec;
                dis[u][v]=min(dis[u][v],w);
                dis[v][u]=min(dis[v][u],w);
            }
        }
    }


        rep(i,1,m){
            rep(j,1,m){
                rep(k,1,m){
             if(i!=j&&j!=k&&i!=k){
                        if(dis[i][k]+dis[k][j]<dis[i][j]){

                            dis[i][j]=dis[i][k]+dis[k][j];
                }

             }
            }
        }
    }
    rep(cas,1,q){
        int x,y;
        cin>>x>>y;
        cout<<dis[x][y]+w[x]+w[y]<<'\n';
    }
    return  0;
}
/*
g++ Untitled.cpp -o Untitled -O2 -std=c++14
g++  home user Untitled.cpp -o Untitled -O2 -std=c++14
*/
