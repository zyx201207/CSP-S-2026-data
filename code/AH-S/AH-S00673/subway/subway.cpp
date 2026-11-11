#include<bits/stdc++.h>
using namespace std;
const long long INF=5000000000000000;
const int MAXM=5e5+5;
const int MAXN=505;
int c,n,m,d,q;
long long w[MAXM];
long long t[MAXN][MAXM];
int ai;
int ki;
int star,en;
vector<int> bel[MAXM];
long long dis[MAXN][MAXN];
typedef pair<int,int> P;
priority_queue<P,vector<P>,greater<P> > Q;
struct edge{
    int w,to;
};
vector<edge> G[MAXN];
int iread(){
    int res=0,sig=1;
    char c;
    c=getchar_unlocked();
    while(c<'0'||c>'9'){
        if(c=='-') sig=-1;
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9'){
        res=res*10+c-'0';
        c=getchar_unlocked();
    }
    return res*sig;
}
void dij(int st){
    Q.push({0,st});
    dis[st][st]=0;
    while(!Q.empty()){
        P H=Q.top();
        Q.pop();
        long long weight=H.first;
        int cur=H.second;
        for(int i=0;i<G[cur].size();i++){
            int to=G[cur][i].to;
            if(dis[st][to]>dis[st][cur]+G[cur][i].w){
                dis[st][to]=dis[st][cur]+G[cur][i].w;
                Q.push({dis[st][to],to});
            }
        }
    }
    return ;
}
void init(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dis[i][j]=INF;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<bel[i].size();j++){
            for(int k=j+1;k<bel[i].size();k++){
                int pla1=bel[i][j];
                int pla2=bel[i][k];
                G[pla1].push_back({t[pla1][i]+t[pla2][i],pla2});
                G[pla2].push_back({t[pla1][i]+t[pla2][i],pla1});
            }
        }
    }
    for(int i=1;i<=n;i++){
        dij(i);
    }
    return ;
}
long long query(int st,int ed){
    long long res=INF;
    for(int i=0;i<bel[st].size();i++){
        for(int j=0;j<bel[ed].size();j++){
            int pla1=bel[st][i];
            int pla2=bel[ed][j];
            res=min(res,dis[pla1][pla2]+t[pla1][st]+t[pla2][ed]+w[st]+w[ed]);
        }
    }
    return res;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    c=iread();
    n=iread();
    m=iread();
    d=iread();
    q=iread();
    for(int i=1;i<=m;i++){
        w[i]=iread();
    }
    for(int i=1;i<=n;i++){
        ki=iread();
        for(int j=1;j<=ki;j++){
            ai=iread();
            t[i][ai]=iread();
            bel[ai].push_back(i);
        }
    }
    init();
    for(int i=1;i<=q;i++){
        star=iread();
        en=iread();
        cout<<query(star,en)<<'\n';
    }
    return 0;
}
