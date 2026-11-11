#include<bits/stdc++.h>
using namespace std;
struct edge{
    pair<int,int> to;
    int cost;
};
struct node{
    int num;
    int line;
};
vector<vector<vector<edge>>> g;
vector<vector<int>> dis;
struct cmp{
    bool operator()(node n1,node n2){
        return dis[n1.num][n1.line]>dis[n2.num][n2.line];
    }
};
int dijkstra(int m,int d,int x,int y){

    vector<vector<bool>> vis(m+1,vector<bool>(d+1,false));
    priority_queue<node,vector<node>,cmp> pq;
    pq.push({x,0});
    dis[x][0]=0;

    while(!pq.empty()){
        node temp=pq.top();
        pq.pop();
        int u=temp.num,v=temp.line;
        if(vis[u][v]) continue;
        vis[u][v]=true;
        for(int i=0;i<g[u][v].size();i++){
            int a=g[u][v][i].to.first,b=g[u][v][i].to.second;
            dis[a][b]=min(dis[a][b],dis[u][v]+g[u][v][i].cost);
            if(!vis[a][b]){
                pq.push({a,b});
            }
        }
    }

    return dis[y][0];
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    g.resize(m+1);
    for(int i=1;i<=m;i++){
        g[i].resize(d+1);
    }

    dis.resize(m+1);
    for(int i=0;i<=m;i++){
        dis[i].resize(d+1);
    }
    for(int i=0;i<=m;i++){
        for(int j=0;j<=d;j++) dis[i][j]=INT_MAX;
    }
    //ditiekou->zhanting
    vector<int> w(m+1);
    for(int i=1;i<=m;i++) scanf("%d",&w[i]);
    //luxian
    vector<int> cur(m+1,0);
    while(n--){
        int k;
        cin>>k;
        int pre=-1;
        for(int i=0;i<k;i++){
            int a,t;
            cin>>a>>t;
            cur[a]++;
            g[a][0].push_back({make_pair(a,cur[a]),t});
            g[a][cur[a]].push_back({make_pair(a,0),t});
            if(pre!=-1){
                g[a][cur[a]].push_back({make_pair(pre,cur[pre]),0});
                g[pre][cur[pre]].push_back({make_pair(a,cur[a]),0});
            }
            pre=a;
        }
    }
    //jihua
    while(q--){
        int x,y;
        scanf("%d %d",&x,&y);
        int temp=dijkstra(m,d,x,y);
        cout<<temp+w[x]+w[y]<<endl;
        for(int i=0;i<=m;i++){
            for(int j=0;j<=d;j++) dis[i][j]=INT_MAX;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
