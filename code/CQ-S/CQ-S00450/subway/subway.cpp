#include<bits/stdc++.h>
using namespace std;
inline char gtchar(){
    static char buf[1<<21],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
    char ch=gtchar();
    int x=0;
    while(ch<'0'||ch>'9') ch=gtchar();
    while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=gtchar();
    return x;
}
int n,m,d,q,w[500005];
long long dis[505][505];
vector<pair<int,int> > g[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    read(),n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;i++) w[i]=read();
    memset(dis,0x3f,sizeof(dis));
    for(int i=1,k;i<=n;i++){
        k=read(),dis[i][i]=0;
        for(int j=1,x,y;j<=k;j++) x=read(),y=read(),g[x].emplace_back(i,y);
    }
    for(int i=1;i<=m;i++){
        for(pair<int,int> j:g[i]){
            for(pair<int,int> k:g[i]) dis[j.first][k.first]=min(dis[j.first][k.first],(long long)(j.second+k.second));
        }
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) for(int k=1;k<=n;k++) dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
    while(q--){
        int x=read(),y=read();
        long long ans=0x3f3f3f3f3f3f3f3f;
        for(pair<int,int> i:g[x]) for(pair<int,int> j:g[y]) ans=min(ans,dis[i.first][j.first]+i.second+j.second);
        printf("%lld\n",ans+w[x]+w[y]);
    }
    return 0;
}