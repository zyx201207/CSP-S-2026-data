#include<bits/stdc++.h>
using namespace std;
const int N=510;
const int M=5e5+10;
int n,m,c;
int d,q;
long long w[M];
int k[N];
struct wsw{
    int a;
    long long t;
};
vector<wsw> vis[M];
long long V[N][N];
bool dis[N][N];
long long zdl[N][N];
struct edge{
    int u,v;
};
priority_queue<edge> pq;
bool operator <(const edge x,const edge y){
    return zdl[x.u][x.v]>zdl[y.u][y.v];
}
long long read(){
    long long x=0;
    char a;
    bool ji=0;
    bool flag=0;
    while(1){
        a=getchar_unlocked();
        if(a=='-') ji=1;
        else if(isdigit(a)){
            flag=1;
            x=(x<<1)+(x<<3)+a-'0';
        }
        else if(flag) break;
    }
    if(ji) x=-x;
    return x;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read();
    n=read();
    m=read();
    d=read();
    q=read();
    for(int i=1;i<=m;i++) w[i]=read();
    for(int i=1;i<=n;i++){
        k[i]=read();
        for(int j=1;j<=k[i];j++){
            int a;
            long long t;
            a=read();
            t=read();
            vis[a].push_back({i,t});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            V[i][j]=LONG_LONG_MAX;
            zdl[i][j]=LONG_LONG_MAX;
            if(i==j) zdl[i][j]=V[i][i]=0;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<vis[i].size();j++){
            for(int k=0;k<vis[i].size();k++){
                V[vis[i][j].a][vis[i][k].a]=min(V[vis[i][j].a][vis[i][k].a],vis[i][j].t+vis[i][k].t);
            }
        }
    }
    for(int i=1;i<=n;i++){
        pq.push((edge){i,i});
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(V[i][j]==LONG_LONG_MAX) continue;
            zdl[i][j]=V[i][j];
            pq.push({i,j});
        }
        while(!pq.empty()){
            edge nw=pq.top();
            pq.pop();
            if(dis[nw.u][nw.v]) continue;
            dis[nw.u][nw.v]=1;
            for(int k=1;k<=n;k++){
                if(k==nw.v) continue;
                if(V[nw.v][k]==LONG_LONG_MAX) continue;
                if(zdl[nw.u][nw.v]+V[nw.v][k]<zdl[nw.u][k]){
                    zdl[nw.u][k]=zdl[nw.u][nw.v]+V[nw.v][k];
                    pq.push({nw.u,k});
                }
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        long long ans=LONG_LONG_MAX;
        x=read();
        y=read();
        for(int j=0;j<vis[x].size();j++){
            for(int k=0;k<vis[y].size();k++){
                ans=min(ans,vis[x][j].t+vis[y][k].t+zdl[vis[x][j].a][vis[y][k].a]);
            }
        }
        ans+=w[x]+w[y];
        printf("%lld\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}