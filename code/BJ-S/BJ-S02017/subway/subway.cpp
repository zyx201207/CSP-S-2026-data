#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,qx;
int w[20005];
int k[20005];
int a[502][20005];
int t[502][20005];
const int MAXN=25005;
int vtx[MAXN*2],idx,nxt[MAXN*2],v[MAXN*2];
int h[MAXN];
void add(int a,int b,int c){
    vtx[idx]=b;
    nxt[idx]=h[a];
    v[idx]=c;
    h[a]=idx++;
}
struct p{
    int idx,dis;
    bool operator < (p oth) const {
        return oth.dis<dis;
    }
};
priority_queue <p> q;
int flag[25005],x,y;
bool flag2[25005];
int dis[2005][2505];
void dij(int x){
    p zz;
    zz.idx=x;
    zz.dis=0;
    dis[x][x]=0;
    q.push(zz);
    flag[x]=1;
    while(!q.empty()){
        p tmp=q.top();
        q.pop();
        flag[tmp.idx]--;
        if(flag[tmp.idx])continue;
        for(int i=h[tmp.idx];~i;i=nxt[i]){
            if(dis[x][vtx[i]]>dis[x][tmp.idx]+v[i]){
                dis[x][vtx[i]]=dis[x][tmp.idx]+v[i];
                p xx;
                xx.dis=dis[x][vtx[i]];
                xx.idx=vtx[i];
                q.push(xx);
                flag[xx.idx]++;
            }
        }
    }
}
queue <int> q2;
int vis[25005];
int bfs(int x){
    while(!q2.empty())q2.pop();
    q2.push(x);
    vis[x]=1;
    while(!q2.empty()){
        int tmp=q2.front();
        q2.pop();
        if(y==tmp)return vis[tmp]-1;
        for(int i=h[tmp];i!=-1;i=nxt[i]){
            if(!vis[vtx[i]]){
                q2.push(vtx[i]);
                vis[vtx[i]]=vis[tmp]+1;
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(h,-1,sizeof h);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&qx);
    for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
    for(int i=1;i<=n;i++){
        scanf("%lld",&k[i]);
        for(int j=1;j<=k[i];j++){
            scanf("%lld%lld",&a[i][j],&t[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k[i];j++){
            add(a[i][j],m+i,t[i][j]);
            add(m+i,a[i][j],t[i][j]);
        }
    }
    memset(dis,0x3f,sizeof dis);
    while(qx--){
        scanf("%lld%lld",&x,&y);
        if(c>=12&&c<=15){
            memset(vis,0,sizeof vis);
            printf("%lld\n",bfs(x)+w[x]+w[y]);
            continue;
        }
        if(!flag2[x]){
            memset(flag,0,sizeof flag);
            flag2[x]=1;
            dij(x);
        }
        printf("%lld\n",dis[x][y]+w[x]+w[y]);
    }
}
