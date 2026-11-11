#include<bits/stdc++.h>
using namespace std;
#define int long long 
void read(int &x){
    char c=getchar();
    bool fl=0;
    x=0;
    while(c<'0'||c>'9'){
        if(c=='-')fl=1;
        c=getchar();
    }
    while('0'<=c&&c<='9'){
        x=x*10+c-'0';
        c=getchar();
    }
    if(fl)x=-x;
}
const int N=5e5+1000;

int c,n,m,d,q;
int w[N];
struct M{
    int v,w;
};
vector<M>g2[N],g[N];
struct cmp{
    bool operator ()(M a,M b){
        return a.w>b.w;
    }
};
int dis[N];
bool vis[N];
priority_queue<M,vector<M>,cmp>pq;
void dj(int st){
    for(int i=1;i<=n;i++){
        vis[i]=0;
        dis[i]=1e15;
    }
    dis[st]=0;
    pq.push({st,0});
    while(!pq.empty()){
        int u=pq.top().v;
        pq.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(M v:g[u]){
            if(vis[v.v]||dis[u]+v.w>=dis[v.v])continue;
            dis[v.v]=dis[u]+v.w;
            pq.push({v.v,dis[v.v]});
        }
    }
}
void write(int x){
    if(x>=10)write(x/10);
    putchar(x%10+'0');
}
int midis[505][505];
signed main(){
  freopen("subway.in","r",stdin);
   freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        read(w[i]);
    }
    for(int i=1;i<=n;i++){
        int k;
        read(k);
        for(int j=1;j<=k;j++){
            int v,ww;
            read(v);
            read(ww);
            g2[i+m].push_back({v,ww});
            g2[v].push_back({m+i,ww});
        }
    }
    memset(midis,0x3f,sizeof midis);
    for(int i=1;i<=n;i++)midis[i][i]=0;
    for(int i=1;i<=m;i++)
    for(M u:g2[i]){
        for(M v:g2[i]){
            midis[v.v-m][u.v-m]=min(midis[v.v-m][u.v-m],u.w+v.w);
            midis[u.v-m][v.v-m]=min(midis[u.v-m][v.v-m],u.w+v.w);
            g[v.v-m].push_back({u.v-m,u.w+v.w});
            g[u.v-m].push_back({v.v-m,u.w+v.w});
        }
    }
    // for(int i=1;i<=n;i++){
    //     dj(i);
    //     for(int j=i+1;j<=n;j++){
    //         midis[i][j]=dis[j];
    //     }
    // }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                midis[i][j]=min(midis[i][k]+midis[k][j],midis[i][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int f,t;
        read(f);
        read(t);
        int ans=1e15;
        for(M u:g2[f]){
            for(M v:g2[t]){
                ans=min(v.w+u.w+midis[u.v-m][v.v-m]+w[f]+w[t],ans);
            }
        }
        write(ans);
        putchar('\n');
    }
    return 0;
}