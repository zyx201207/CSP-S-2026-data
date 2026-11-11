#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7+10;
int C,n,m,d,que;
struct node{
    int v,c,nxt;
}e[maxn<<1];
int h[maxn],tot;
void addEdge(int u,int v,int c){
    ++tot;
    e[tot].v=v;
    e[tot].c=c;
    e[tot].nxt=h[u];
    h[u]=tot;
}
struct Queue{
    int v,dis;
    bool operator < (const Queue &T)const {
        return dis>T.dis;
    }
};
priority_queue<Queue> q;
bool vis[maxn];
int dis[maxn];
int dijkstra(int s,int t){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    while(!q.empty())q.pop();
    dis[s]=0;
    q.push({s,0});
    while(!q.empty()){
        int u=q.top().v;
        q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(int i=h[u];i;i=e[i].nxt){
            int v=e[i].v;
            if(vis[v])continue;
            if(dis[v]>dis[u]+e[i].c){
                dis[v]=dis[u]+e[i].c;
                q.push({v,dis[v]});

            }
        }
    }
    return dis[t];
}
int sl[500010][510];
//     station line = line'
int sltot[500010];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> C >> n >> m >> d >> que ;
    for(int i=1;i<=m;i++){//station
        int c;
        cin >> c ;
        addEdge(i*(d+2)+1,i*(d+2)+2,c);
        addEdge(i*(d+2)+2,i*(d+2)+1,c);
    }
    for(int i=1;i<=n;i++){//line
        int k;
        cin >> k ;
        int sta[k+2]={0};
        for(int j=1;j<=k;j++){
            cin >> sta[j] ;
            sl[sta[j]][i]=++sltot[sta[j]];
            int tik;
            cin >> tik;
            addEdge(sta[j]*(d+2)+2,sta[j]*(d+2)+2+sl[sta[j]][i],tik);
            addEdge(sta[j]*(d+2)+2+sl[sta[j]][i],sta[j]*(d+2)+2,tik);
        }
        for(int j=1;j<=k-1;j++){
            addEdge(sta[j]*(d+2)+2+sl[sta[j]][i],sta[j+1]*(d+2)+2+sl[sta[j+1]][i],0);
            addEdge(sta[j+1]*(d+2)+2+sl[sta[j+1]][i],sta[j]*(d+2)+2+sl[sta[j]][i],0);
        }
    }
    for(int i=1;i<=que;i++){
        int st,te;
        cin >> st >> te ;
        cout << dijkstra(st*(d+2)+1,te*(d+2)+1) << '\n' ;
    }
    return 0;
}
