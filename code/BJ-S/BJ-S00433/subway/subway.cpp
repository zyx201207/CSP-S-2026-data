#include<bits/stdc++.h>
using namespace std;
struct node{
    int w,idx,lines[510],t[510];
}station[500010];
int C,n,m,d,Q;
long long dis[510];
vector<int> sst;
int g[510][510];
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
void add(int x,int y,int z){
    g[x][y]=g[y][x]=z;
    return;
}
void build(){
    memset(g,0x3f,sizeof g);
    for(int i=1;i<=n;i++) g[i][i]=0;
    for(int i=1;i<=m;i++){
        station[i].w=read();
    }
    for(int i=1;i<=n;i++){
        int k=read();
        for(int j=1;j<=k;j++){
            int x=read(),y=read();
            station[x].lines[++station[x].idx]=i;
            station[x].t[station[x].idx]=y;
            if(station[x].idx==2){
                sst.push_back(x);
            }
        }
    }
    for(int i=0;i<sst.size();i++){
        node x=station[sst[i]];
        for(int i=1;i<=x.idx;i++){
            for(int j=i+1;j<=x.idx;j++){
                add(x.lines[i],x.lines[j],x.t[i]+x.t[j]);

            }
        }
    }
    return;
}
void Floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(g[i][j]>g[i][k]+g[j][k]){
                    g[i][j]=g[j][i]=g[i][k]+g[j][k];
                }
            }
        }
    }
    return;
}
void solve(int sts,int eds){
    node sx=station[sts],ex=station[eds];
    long long ans=1e18;
    for(int i=1;i<=sx.idx;i++){
        for(int j=1;j<=ex.idx;j++){
            ans=min(ans,((long long)(sx.w+ex.w+sx.t[i]+ex.t[j]+g[sx.lines[i]][ex.lines[j]])));
        }
    }
    printf("%d\n",ans);
    return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&C,&n,&m,&d,&Q);
    build();
    Floyd();
    while(Q--){
        int sts=read(),eds=read();
        solve(sts,eds);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
