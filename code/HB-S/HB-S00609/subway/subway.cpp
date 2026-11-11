#include<bits/stdc++.h>
using namespace std;

#define REP(a,b,c) for(int a = (b);(a) <= (c);++a)
#define DOW(a,b,c) for(int a = (b);(a) >= (c);--a)
#define pr printf
#define sc scanf
#define Pb push_back
#define fi first
#define se second
#define Sz(v) (int(v.size()))
#define FALL(v) v.begin(),v.end()

typedef long long ll;
typedef pair<int,int> P2i;

const int MAXN = 505;
const int MAXNm = 5e5+5;
const int MOD = 0;

/*
g++ -O2 -std=c++14 -static subway.cpp -o subway.exe
./subway.exe
*/

struct Edge{
    int v,w;
};

vector<Edge> G[MAXN];
bitset<MAXNm> vis;

void addE(int u,int v,int w){
    G[u].Pb({v,w});
    G[v].Pb({u,w});
    return;
}

ll dis[MAXN][MAXN];

void Dij(int s){
    dis[s][s] = 0;
    vis.reset();
    priority_queue<P2i,vector<P2i>,less<P2i>> pq;
    pq.push({0,s});
    while(!pq.empty()){
        int u = pq.top().se,disu = pq.top().fi; pq.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(const Edge& ed : G[u]){
            int v = ed.v,w = ed.w;
            if(dis[s][v] > dis[s][u]+w){
                dis[s][v] = dis[s][u]+w;
                pq.push({dis[s][v],v});
            }
        }
    }
}

int main(){

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    int c,n,m,d,q;
    sc("%d%d%d%d%d",&c,&n,&m,&d,&q);
    vector<int> w(m+5),k(n+5);
    REP(i,1,m) sc("%d",&w[i]);
    vector<vector<Edge>> M(m+5,vector<Edge>());

    REP(i,1,n){ //Line i
        sc("%d",&k[i]);
        REP(jt,1,k[i]){
            int a,t;
            sc("%d%d",&a,&t); //Site a
            M[a].Pb({i,t});
        }
    }

    REP(jt,1,m){
        int Mx = Sz(M[jt]);
        REP(i,0,Mx-1){
            REP(j,i+1,Mx-1){
                addE(M[jt][i].v,M[jt][j].v,M[jt][i].w+M[jt][j].w);
            }
        }
    }

    REP(i,1,n) REP(j,1,n) dis[i][j] = 1LL*1e15;
    REP(i,1,n) Dij(i);
    REP(jt,1,q){
        int u,v; sc("%d%d",&u,&v);
        ll ans = 1e15;
        REP(i,0,Sz(M[u])-1){
            REP(j,0,Sz(M[v])-1){
                ans = min(ans,
                M[u][i].w+M[v][j].w+dis[M[u][i].v][M[v][j].v]);
            }
        }
        pr("%lld\n",ans+w[u]+w[v]);
    }

    return 0;
}