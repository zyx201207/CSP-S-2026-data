#include<bits/stdc++.h>
using namespace std;
const int N=5e6+5,M=2e6+5;
int st[N],idx,a[N],num[N];
struct edge{
    int to;
    long long val;
    bool operator<(const edge &a)const{
        return val>a.val;
    }
};
vector<edge>g[M];
long long dist[M];
bool vis[M];
void dijkstra(int s,int e){
    for(int i=1;i<=idx;i++){
        dist[i]=LLONG_MAX;
        vis[i]=false;
    }
    dist[s]=0;
    priority_queue<edge>q;
    q.push({s,0});
    while(!q.empty()){
        int u=q.top().to;
        q.pop();
        if(vis[u])
            continue;
        vis[u]=true;
        for(auto node:g[u]){
            int to=node.to,val=node.val;
            if(dist[u]+node.val<dist[to]){
                dist[to]=dist[u]+node.val;
                q.push({to,dist[to]});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        int x;
        scanf("%d",&x);
        g[i].push_back({i+m,x});
        g[i+m].push_back({i,x});
    }
    idx=2*m;
    int cnt=0;
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            int t;
            scanf("%d%d",&a[j],&t);
            num[a[j]]=++cnt;
            st[num[a[j]]]=++idx;
            if(j>=2){
                g[st[num[a[j]]]].push_back({st[num[a[j-1]]],0});
                g[st[num[a[j-1]]]].push_back({st[num[a[j]]],0});
//                cout<<"station: "<<st[num[a[j-1]]]<<" "<<st[num[a[j]]]<<endl;
            }
            g[st[num[a[j]]]].push_back({a[j]+m,t});
            g[a[j]+m].push_back({st[num[a[j]]],t});
        }
    }
    int lstx=-1,lsty=-1;
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        if(x==lstx){
            printf("%lld\n",dist[y]);
            continue;
        }
        dijkstra(x,y);
        printf("%lld\n",dist[y]);
//        cout<<dist[11]<<endl;
//        cout<<dist[y]<<endl;
        lstx=x;
        lsty=y;
    }
    return 0;
}
