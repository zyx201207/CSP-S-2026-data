#include<bits/stdc++.h>
using namespace std;
const int MAXN=505,MAXM=5e5+5;
struct shiroi{
    int to;
    long long data;
};
int hao,n,m,d,q;
long long w[MAXM],dis[MAXN][MAXN];
vector<shiroi> g[MAXM];
inline int read(){
    int x=0;
    char c;
    c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9'){
        x=x*10+c-'0';
        c=getchar();
    }
    return x;
}
inline void write(long long x){
    if(x<10){
        putchar(x+'0');
        return ;
    }
    write(x/10);
    putchar(x%10+'0');
    return ;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    hao=read();n=read();m=read();d=read();q=read();
    for(int i=1;i<=m;++i) w[i]=read();
    for(int i=1;i<=n;++i){
        int pos,k;long long time;
        k=read();
        for(int j=1;j<=k;++j){
            pos=read();time=read();
            g[pos].push_back({i,time});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;++j) dis[i][j]=1e18;
        dis[i][i]=0;
    }
    for(int i=1;i<=m;++i){
        for(int j=0;j<g[i].size();++j){
            for(int k=0;k<g[i].size();++k){
                if(j==k) continue;
                int u=g[i][j].to,v=g[i][k].to;
                if(dis[u][v]>g[i][j].data+g[i][k].data) dis[u][v]=dis[v][u]=g[i][j].data+g[i][k].data;
            }
        }
    }
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(dis[i][j]>dis[i][k]+dis[k][j]) dis[i][j]=dis[i][k]+dis[k][j];
            }
        }
    }
    while(q--){
        int st,ed;
        long long ans=1e18;
        st=read();ed=read();
        for(int i=0;i<g[st].size();i++){
            for(int j=0;j<g[ed].size();j++){
                ans=min(ans,g[st][i].data+g[ed][j].data+dis[g[st][i].to][g[ed][j].to]);
            }
        }
        write(ans+w[st]+w[ed]);
        putchar('\n');
    }
    return 0;
}