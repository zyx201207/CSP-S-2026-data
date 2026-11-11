#include<bits/stdc++.h>

typedef long long LL;
typedef unsigned long long ULL;

#define mkp make_pair
#define PII pair<int,int>
#define PLI pair<LL,int>
#define fst first
#define sec second
#define psh push
#define pb push_back

using namespace std;

const int N=520,PT=(N+3)*1e5;
const int M=5e5+10,ES=5e6+10;
const LL INF=1e18;
const LL IDK=1e10;

int n,m;
int D,Q;
int W[M];

int K[N];
vector<int>a[N],t[N];

int ecnt,head[N],nxt[ES],to[ES];
LL val[ES];
void add(int x,int y,LL z){
    nxt[++ecnt]=head[x];
    head[x]=ecnt;
    to[ecnt]=y;
    val[ecnt]=z;
    return;
}
void add_edge(int x,int y,LL z){
    add(x,y,z),add(y,x,z);
    return;
}

int ptcnt;// point_cnt

priority_queue<PLI,vector<PLI>,greater<PLI>>q;
bool vis[PT];
LL dis[PT];
void dij(int st){
    for(int i=1;i<=ptcnt;i++) dis[i]=INF,vis[i]=0;

    dis[st]=0;
    q.psh({dis[st],st});

    while(!q.empty()){
        int u=q.top().sec;
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;

        for(int i=head[u];i;i=nxt[i]){
            int v=to[i];
            LL w=val[i];
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                q.psh({dis[v],v});
            }
        }
    }
    return;
}

int main(){
    freopen("subway.in","r",stdin);
//    freopen("subway1.in","r",stdin);
    freopen("subway.out","w",stdout);

    int tstid;
    scanf("%d %d %d %d %d",&tstid,&n,&m,&D,&Q);
    ptcnt=(n+2)*m;

    for(int i=1;i<=m;i++) scanf("%d",&W[i]);

    for(int i=1;i<=n;i++){
        scanf("%d",&K[i]);
//        for(int j=1,ed=K[i]*2,x;j<=ed;j++){
        for(int j=1,x;j<=K[i];j++){
            scanf("%d",&x);a[i].pb(x);
            scanf("%d",&x);t[i].pb(x);
            // add_edge(a[i][j-1],a[i][j-1]+m,t[i][j-1]);
            // add_edge(a[i][j-1],2*m+i*a[i][j-1],t[i][j-1]);
//            add_edge(m+a[i][j-1],2*m+i*a[i][j-1],t[i][j-1]);
//            add_edge(a[i][j-1],m+a[i][j-1],0);
//            add(2*m+i*a[i][j-1],);
			add_edge(a[i][j-1],2*m+i*a[i][j-1],IDK);
			add_edge(2*m+i*a[i][j-1],m+a[i][j-1],t[i][j-1]);
        }
//        for(int j=1,ed=K[i]*2;j<ed;j++){
        for(int j=1;j<K[i];j++){
            add_edge(a[i][j],a[i][j-1],IDK);
        }
    }

    while(Q--){
        int x,y;
        scanf("%d %d",&x,&y);
        dij(x);
        printf("%lld\n",dis[y]);
//		for(int i=1;i<=ptcnt;i++) printf("%lld ",dis[i]);putchar('\n');
//		for(int i=1;i<=m;i++) printf("%lld ",dis[i]);putchar('\n');
    }

    return 0;
}
