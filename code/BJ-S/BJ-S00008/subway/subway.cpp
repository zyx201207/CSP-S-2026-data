#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define gc getchar_unlocked
#define pc putchar_unlocked



ll read(){
    ll x=0,f=1;
    ll ch=gc();
    while(!isdigit(ch)) {
        if(ch=='-')f=-1;
        ch=gc();
    }
    while(isdigit(ch)) {
        x=(x<<3)+(x<<1)+(ch^48);
        ch=gc();
    }
    return x*f;
}
void write(ll x) {
    ll stk[48],t=0;
    if(x<0)pc('-'),x=-x;
    if(x==0)pc('0');
    while(x)stk[t++]=x%10,x/=10;
    for(int i=t-1;i>=0;i--) {
        pc(stk[i]^48);
    }
    pc('\n');
}

namespace cd{
    struct nd {
        ll v,w;
    };
    bool operator<(nd x,nd y) {
        return x.w>y.w;
    }
    vector<nd> g[1100007];
    ll dis[1100007];bool vis[1100007];
    priority_queue<nd> pq;
    void dijkstra(ll s) {
        memset(dis,0x3f,sizeof(dis));
        memset(vis,0,sizeof(vis));
        dis[s]=0;
        pq.push({s,0});nd u;
        while(!pq.empty()) {            u=pq.top();pq.pop();
            for(nd ed:g[u.v]) {
                if(vis[ed.v])continue;
                vis[ed.v]=1;
                if(dis[u.v]+ed.w<dis[ed.v]) {
                    dis[ed.v]=dis[u.v]+ed.w;
                    pq.push({ed.v,dis[ed.v]});
                }
            }
        }
    }
    ll cesd,n,m,d,q;
    // For point P -> Exit: P
    //             -> Conc: n+P
    // For superPoint for Line X -> 1000002+X

    ll pttop;ll w[500007];ll a[507][20007],t[507][20007],p[507][20007],k[507],x,y;
    int main() {
        freopen("subway.in","r",stdin);
        freopen("subway.out","w",stdout);
        cesd=read();
        n=read();m=read();d=read();q=read();
        for(int i=1;i<=m;i++)w[i]=read();
        for(int i=1;i<=n;i++) {
            k[i]=read();
            for(int j=1;j<=k[i];j++) {
                a[i][j]=read();t[i][j]=read();

            }
        }
        // create graph
        // Exit to Station
        for(int i=1;i<=m;i++) {
            g[i].push_back({m+i,w[i]});
            g[m+i].push_back({i,w[i]});
        }
                pttop=2*m+2;
        // station to Platform + Platform to SuperPoint
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=k[i];j++) {
                g[a[i][j]+m].push_back({pttop,t[i][j]});
                g[pttop].push_back({a[i][j]+m,t[i][j]});
                g[pttop].push_back({1000002+i,0});
                g[1000002+i].push_back({pttop,0});
                pttop++;
            }
        }
        while(q--) {
            x=read();y=read();
            dijkstra(x);
            write(dis[y]);
        }
        return 0;
    }
}
int main(){return cd::main();}

// woShiQU
//freopen
//woxihuannimen!
// nan yi 1=
// %%% julao
// luogu uid=1435654, @beijing101highSchoolKaodian.-104Seat1
// Oct31==Dec25?
// T1 done on 16:03
// T2 done on 16:48

