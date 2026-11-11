#include<bits/stdc++.h>
using namespace std;

const int N=1000005;
vector<int>E[N];
int Tid,Tcnt,n,K,qp[N],ans;
int dis[N],head,tail,vis[N],tim;

template<typename qwq>inline void cmin(qwq &a,qwq b){(a>b)&&(a=b);}
template<typename qwq>inline void cmax(qwq &a,qwq b){(a<b)&&(a=b);}

template<typename qwq>inline void read(qwq &a){
    a=0;int c=getchar(),f=0;
    while(!isdigit(c)) f|=c=='-',c=getchar();
    while(isdigit(c)) a=10*a+c-'0',c=getchar();
    if(f) a=-a;
}

inline int bfs(int op=0){
    ++tim;
    for(int i=head;i<tail;i++) dis[qp[i]]=0,vis[qp[i]]=tim;
    if(op){
        int e=0;
        for(int i=head;i<tail;i++){
            int u=qp[i];
            for(auto &v:E[u]) e+=vis[v]==tim;
        }
        e/=2,e=K-e;
        if(e>2) return ans;
    }
    for(int u;head<tail;){
        u=qp[head++];
        for(auto &v:E[u]){
            if(vis[v]==tim) continue;
            vis[v]=tim,dis[v]=dis[u]+1,qp[tail++]=v;
            if(dis[v]>=ans) return ans;
        }
    }
    return dis[qp[tail-1]];
}

void subtask1(){
    int up=(1<<n)-1;
    for(int i=1;i<=up;i++){
        if(__builtin_popcount(i)!=K) continue;
        head=0,tail=0;
        for(int j=0;j<n;j++){
            if((i>>j)&1) qp[tail++]=j+1;
        }
        cmin(ans,bfs(1));
    }
    printf("%d\n",ans);
}

void subtask2(){
    for(int i=1;i<=n;i++){for(int j=i+1;j<=n;j++){
        head=0,tail=0,qp[tail++]=i,qp[tail++]=j,cmin(ans,bfs());
    }}
    printf("%d\n",ans);
}

void solve(){
    read(n),read(K),ans=n;
    for(int i=1,u,v;i<n;i++){
        read(u),read(v);
        E[u].emplace_back(v),E[v].emplace_back(u);
    }
    if(K<=2) subtask2();
    else if(n<=10) subtask1();
    for(int i=1;i<=n;i++){
        vector<int>().swap(E[i]);
    }
}

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    for(read(Tid),read(Tcnt);Tcnt--;) solve();
    return 0;
}
/*
code by Wxb2010
*/