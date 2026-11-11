#include<cstring>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int c,n,m,t;

struct E{
    int v,w;
};

vector<E>G[500505];
int ans=1;
ll x[2000005];
ull d;

struct qn{
    int i; ull d;
    bool operator< (const qn &b) const{
        return d>b.d; // REV -- turn to small-heap
    }
};
#define DEBUG 0

#define D(x) if(dbg&(1<<x))
ull dbg=(
(1<<0)|
(1<<1)|
(1<<2)|
(1<<3)|
(1<<4)|
(1<<5)|
// ENABLE/DISABLE DEBUG
0);
#if DEBUG
char buf[65535];
#else
char buf[256];
#endif
// #define DPR(x) { char t[256]; sprintf(t,x); cout << t; }

ull pc[2000005],dt[2000005];

void DJK(int ss){
    for(int i=1;i<=n+1;++i)dt[i]=0x7f7f7f7f7f7f7f7f;
    for(int i=1;i<=n+1;++i)pc[i]=0;
    queue<qn> q;
    q.push({ss,0});
    dt[ss]=0;
    while(!q.empty()){
        qn u=q.front(); q.pop();
        D(3) printf("DJK %d cdt %d\n",u.i,u.d);
        if(u.d>dt[u.i])continue;
        for(int v=1;v<=n;++v){
            if(abs(x[v]-x[u.i])>d)continue;
            if(dt[v]>u.d+1){
                dt[v]=u.d+1;
                q.push({v,dt[v]});
                pc[v]=1;
            }else if(dt[v]==u.d+1){
                ++pc[v];
            }
        }
    }
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    char *bp=buf;
    if(!DEBUG)dbg=0;
// ====================================
    scanf("%d%d",&c,&t);
    while(t--){
        scanf("%d%llu",&n,&d);
        for(int i=1;i<=n;++i)scanf("%lld",x+i);
        if(n-3<1){
            printf("0\n");
            continue;
        }
        ull ans=0;
        for(int s=1;s<=n-1;++s){
            // for(int i=s;i<=n;++i) pc[i]=0;
            DJK(s);
            for(int e=s+1;e<=n;++e){
                if(pc[e]==2)++ans;
            }
        }
        printf("%d\n",ans);
    }
end:
    if(DEBUG)cout<<buf;
    return 0;
}