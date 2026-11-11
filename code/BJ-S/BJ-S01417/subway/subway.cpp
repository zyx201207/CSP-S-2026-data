#include<cstdio>
#include<vector>
#include<utility>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1000505;
vector<pair<int,int> > G[N];
int dis[N],w[N];
bool vis[N];
struct Node{
    int v,w;
    friend bool operator <(const Node x,const Node y){
        return x.w>y.w;
    }
};
Node make_node(int x,int y){
    Node ans;
    ans.v=x;ans.w=y;
    return ans;
}
void Dijkstra(int st){
    priority_queue<Node> pq;
    memset(dis,0x3f,sizeof dis);
    memset(vis,0,sizeof vis);

    pq.push(make_node(st,0));
    dis[st]=0;
    while(!pq.empty()){
        Node cur=pq.top();
        pq.pop();
        
        int u=cur.v;
        if(vis[u]) continue;
        vis[u]=true;

        for(vector<pair<int,int> >::iterator it=G[u].begin();it!=G[u].end();it++){
            int v=it->first,w=it->second;
            if((!vis[v])&&dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                pq.push(make_node(v,dis[v]));
            }
        }
    }
}
struct Query{
    int x,y,idx,ans;
};
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    // if(c<=6){
        for(int i=1;i<=m;i++) scanf("%d",&w[i]);
        for(int i=1;i<=n;i++){
            int curk;
            scanf("%d",&curk);
            for(int j=1;j<=curk;j++){
                int cura,curt;
                scanf("%d%d",&cura,&curt);
                G[cura].push_back(make_pair(m+i,curt));
                G[m+i].push_back(make_pair(cura,curt));
            }
        }
        vector<Query> query;
        for(int i=1;i<=q;i++){
            int curx,cury;
            scanf("%d%d",&curx,&cury);
            query.push_back({curx,cury,i,0});
        }
        sort(query.begin(),query.end(),[](const Query x,const Query y){
            return x.x<y.x;
        });
        for(int i=0;i<q;i++){
            if(i!=0&&query[i-1].x==query[i].x){
                query[i].ans=dis[query[i].y]+w[query[i].x]+w[query[i].y];
                continue;
            }
            Dijkstra(query[i].x);
            query[i].ans=dis[query[i].y]+w[query[i].x]+w[query[i].y];
        }
        sort(query.begin(),query.end(),[](const Query x,const Query y){
            return x.idx<y.idx;
        });
        for(vector<Query>::iterator it=query.begin();it!=query.end();it++) printf("%d\n",it->ans);
        // while(q--){
        //     int curx,cury;
        //     scanf("%d%d",&curx,&cury);

        //     Dijkstra(curx);
        //     printf("%d\n",dis[cury]+w[curx]+w[cury]);
        // }
    // }
    return 0;
}