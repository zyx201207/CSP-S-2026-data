#include<cstring>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int c,n,m,d,q;

struct E{
    int v,w;
};
// 1~m for station, m+i for line
vector<E>G[500505];
int ans=1;
ll cexit[500005];
ull dt[500505];
struct Q{
    int i,s,e;
    bool operator< (const Q &b) const{
        if(s==b.s){
            return e<b.e;
        }
        return s<b.s;
    }
} qs[100005];
ull qres[100005];

#define DEBUG 0

#define D(x) if(dbg&(1<<x))
ull dbg=(
(1<<0)| // progree
(1<<1)| // conn edge
(1<<2)| // dump dt+exit
(1<<3)| // DJK
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


int dtm[505][505];

struct qn{
    int i; ull d;
    bool operator< (const qn &b) const{
        return d>b.d; // REV -- turn to small-heap
    }
};
priority_queue<qn> cacheq;
int caches;
void DJK(int ss,int ee){
        priority_queue<qn> q;
    if(ss!=caches){
        for(int i=1;i<=n+m;++i)dt[i]=0x7f7f7f7f7f7f7f7f;
        q.push({ss,0});
        dt[ss]=0;
    }else{
        q=cacheq;
        // printf("cache HIT s %d e %d\n",ss,ee);
    }
    while(!q.empty()){
        qn u=q.top(); q.pop();
        D(3) printf("DJK %d cdt %d\n",u.i,u.d);
        if(u.d>dt[u.i])continue;
        if(u.i==ee){
            q.push(u);
            cacheq=q;
            caches=ss;
            return;
        }
        for(E e:G[u.i]){
            D(3) printf("v %d, dt %d, MYE %d\n",e.v,dt[e.v],u.d+e.w);
            if(dt[e.v]>u.d+e.w){
                dt[e.v]=u.d+e.w;
                q.push({e.v,dt[e.v]});
            }
        }
    }
}
// ======================================================================
void DJKM(int ss){
    priority_queue<qn> q;
    q.push({ss,0});
    dt[ss]=0;
    while(!q.empty()){
        qn u=q.top(); q.pop();
        D(3) printf("DJK %d cdt %d\n",u.i,u.d);
        if(u.d>dt[u.i])continue;
        for(int v=1;v<=n;++v){
            // if(dtm[u.i][v]>=0x7f7f7f7f)continue;
            if(dt[v]>u.d+dtm[u.i][v]){
                dt[v]=dtm[u.i][v];
                q.push({v,dt[v]});
            }
        }
    }
    for(int i=1;i<=n;++i)dt[i]=0x7f7f7f7f7f7f7f7f;
}



int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    char *bp=buf;
    if(!DEBUG)dbg=0;
// ====================================
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    if(d==2){
        memset(dtm,0x7f,sizeof(dtm));
    }
    for(int i=1;i<=m;++i)scanf("%d",cexit+i);
    int ki,ss,ee;
    for(int i=1;i<=n;++i){
        scanf("%d",&ki);
        int ai,ti;
        for(int _=1;_<=ki;++_){
            scanf("%d%d",&ai,&ti);
            D(1) printf("CONNECT STA %d <==%d==> VLP %d\n",ai,ti,i+m);
            G[i+m].push_back({ai,ti});
            G[ai] .push_back({i+m,ti});
        }
    }
    for(int qq=1;qq<=q;++qq){
        scanf("%d%d",&ss,&ee);
        qs[qq]={qq,ss,ee};
    }
    sort(qs+1,qs+q+1);
    if(d==2){
        for(int i=1;i<=m;++i){
            if(G[i].size()!=2)continue;
            E ae=G[i][0],be=G[i][1];
            if(dtm[ae.v-m][be.v-m]<ae.w+be.w){
                dtm[ae.v-m][be.v-m]=ae.w+be.w;
                dtm[be.v-m][ae.v-m]=ae.w+be.w;
            }
        }
        for(int i=1;i<=q;++i){
            Q cq=qs[i];
            ull da=0x7f7f7f7f7f7f7f7f;
            for(E se:G[cq.s]){
                DJKM(se.v-m);
                for(E ene:G[cq.e]){
                    da=min(da,dt[ene.v-m]);
                }
            }
            D(2) printf("X%d--%d-->S%d==%d==>S%d--%d-->X%d\n", \
            cq.s,cexit[cq.s],cq.s,dt[cq.e],cq.e,cexit[cq.e],cq.e);
            qres[cq.i]=0ll+cexit[cq.s]+cexit[cq.e]+da;
        }
        for(int i=1;i<=q;++i){
            printf("%llu\n",qres[i]);
        }
        return 0;
    }
    for(int i=1;i<=q;++i){
        Q cq=qs[i];
        DJK(cq.s,cq.e);
        D(2) printf("X%d--%d-->S%d==%d==>S%d--%d-->X%d\n", \
        cq.s,cexit[cq.s],cq.s,dt[cq.e],cq.e,cexit[cq.e],cq.e);
        qres[cq.i]=0ll+cexit[cq.s]+cexit[cq.e]+dt[cq.e];
    }
    for(int i=1;i<=q;++i){
        printf("%llu\n",qres[i]);
    }
end:
    if(DEBUG)cout<<buf;
    return 0;
}