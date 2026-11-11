#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

namespace IO{
    struct INID{INID(){ios::sync_with_stdio(false);cin.tie(nullptr);}};
    int gc(){return cin.rdbuf()->sbumpc();}
    void pc(char c){cout.rdbuf()->sputc(c);}
    template<typename T>void rd(T &x){
        x=0;int f=1,c=gc();
        while('0'>c||c>'9'){
            if(c==EOF){cerr<<"IIE";exit(0);}
            if(c=='-'){f*=-1;}
            c=gc();
        }
        while('0'<=c&&c<='9'){
            x=x*10+c-'0';
            c=gc();
        }
        x*=f;
    }
    template<typename T>void wt(T x){
        if(x<0){pc('-');}
        static int stk[40],tp,d;
        tp=0;
        do{
            d=x%10;
            stk[++tp]=(d<0?-d:d)+'0';
            x/=10;
        }while(x);
        while(tp){pc(stk[tp--]);}
    }
}using namespace IO;

#define int long long

constexpr int N=5e3+6;
constexpr int M=N*N;
constexpr int inf=0x3f3f3f3f3f3f3f3f;

int c,n,d;

int x[N];
int dis[N];
int cnt[N];
int ans;

struct edge{
    int nxt,to,val;
}e[M];
int hd[N],cntE;
void add(int u,int v,int w){
    e[++cntE]={hd[u],v,w};
    hd[u]=cntE;
}

struct node{
    int u,disu;
    bool operator<(const node& o)const{
        return disu>o.disu;
    }
};

priority_queue<node>q;

int vis[N];

void dij(int s){
    while(!q.empty()){
        q.pop();
    }
    for(int i=1;i<=n;++i){
        dis[i]=inf;
        cnt[i]=0;
        vis[i]=0;
    }
    dis[s]=0;
    cnt[s]=1;
    vis[s]=1;
    q.push({s,0});
    while(!q.empty()){
        int u=q.top().u;
        int disu=q.top().disu;
        q.pop();
        vis[u]=0;
        if(dis[u]!=disu){
            continue;
        }
        for(int i=hd[u];i;i=e[i].nxt){
            int v=e[i].to;
            int w=e[i].val;
            int nw=w+dis[u];
            if(dis[v]>nw){
                dis[v]=nw;
                cnt[v]=cnt[u];
                vis[v]=1;
                q.push({v,dis[v]});
            }else if(dis[v]==nw){
                cnt[v]+=cnt[u];
                if(!vis[v]){
                    q.push({v,dis[v]});
                    vis[v]=1;
                }
            }
        }
    }
    for(int i=1;i<=n;++i){
        if(cnt[i]==2){
            ++ans;
        }
    }
}


void global(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    rd(c);
}

namespace tqy{
    void init(){
        rd(n),rd(d);
        for(int i=1;i<=n;++i){
            rd(x[i]);
        }
        ans=0;
        for(int i=1;i<=n;++i){
            hd[i]=0;
        }
        cntE=0;
    }   
    void solve(){
        
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(abs(x[i]-x[j])<=d){
                    add(i,j,1);
                }
            }
        }
        // exit(0);
        for(int i=1;i<=n;++i){
            dij(i);
        }
        wt(ans/2);
        pc('\n');
    }
}

signed main(){
    global();
    int T=1;rd(T);
    while(T--)tqy::init(),tqy::solve();
    return 0;
}

/*

g++ 3.cpp -o 3 -O2 -static -std=c++14
 -Wall -fsanitize=leak,address,undefined

考虑说固定一个岛屿

最短路必须有两条，且只能有两条

期望24pts

*/