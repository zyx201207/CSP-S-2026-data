#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int M = 20000+9;
const int N = 1000+9;
struct node{//编号 + 时间
    ll v;
    ll w;
};
ll c,n,m,d,q;
ll w[M] ;//m个站点
int cnt[N] ;//n条线路的每个
int num = 0 ,num1;
bool flag = 1;
vector<node> a[N] ;//n条线路
vector<node> adj[M];
ll dp[N][N] ;
ll dis[N][N] ;
bool vis[N][N] ;

void handle(){
    //0.初始化
    for(int i = 1 ;i <= m ; i ++ ){
        for(int j = 1 ; j <= m ; j ++ ){
            dp[i][j] = 1e18 ;
        }
    }
    //1.同一条的从i站厅到j展厅
    for(int i = 1 ;i <= n ; i ++ ){
        for(int j = 0 ; j < cnt[i]; j ++ ){
            for(int g = 0 ; g < cnt[i] ; g ++ ){
                int id1 = a[i][j].v;
                int id2 = a[i][g].v;
                dp[id1][id2] = a[i][j].w + a[i][g].w ;
            }
        }
    }
    //2.不同的
    for(int g = 1 ; g <= m ; g ++ ){
        for(int i = 1 ; i <= m ; i ++ ){
            for(int j = 1 ; j <=m ; j ++ ){
                dp[i][j] = min(dp[i][g]+dp[g][j],dp[i][j]);
            }
        }
    }
}

bool operator < (const node &x,const node &y){
    return x.w > y.w ;
}

void dijkstra(int s){
    priority_queue<node> pq;
    dis[s][s]=0 ;
    pq.push({s,0});
    while(!pq.empty()){
        int u = pq.top().v;
        pq.pop();
        if(vis[s][u]) continue ;
        vis[s][u] = 1;
        for(auto x:adj[u]){
            ll v = x.v;
            ll w = x.w;
            if(dis[s][v] > dis[s][u]+w){
                dis[s][v] = dis[s][u]+w;
                pq.push({v,dis[s][v]});
            }
        }
    }
}


int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1 ; i <= m ; i ++ ){
        cin >> w[i] ;
    }
    int w1;
    for(int i = 1 ; i <= n ; i ++ ){
        int k,v,w;
        cin >> k;
        cnt[i] = k;
        num = max(num,k);
        for(int j = 1 ; j <= k ; j ++ ){
            cin >> v >> w;
            if(i==1&&j==1) w1 = w ;
            if(w != w1) flag = 0 ;
            num1 = w ;
            a[i].push_back({v,w});
        }
    }
    //特殊性质A：
    if(num <= 2){
            //0.初始化
        for(int i = 1 ; i <= m ;i ++ ){
            for(int j = 1 ; j <= m ; j ++ ){
                dis[i][j] = 1e18 ;
            }
        }
            //1.建图
        for(int i = 1 ; i <= n ; i ++ ){
            if(cnt[i]==1) continue ;
            ll u = a[i][0].v;
            ll v = a[i][1].v;
            ll w = a[i][0].w+a[i][1].w ;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        //跑m遍dijkstra!!!
        for(int i = 1 ; i <= m ; i ++ ){
            dijkstra(i);
        }
        while(q--){
            int s,e;
            cin >> s >> e ;
            cout<<w[s]+dis[e][s]+w[e]<<endl;
        }
        return 0;
    }
    if(flag){
        //cout<<"yes"<<endl;
        for(int i = 1 ; i <= n ; i ++ ){
            for(int j = 1 ; j <= n ; j ++ ){
                dis[i][j] = 1e18 ;
            }
        }
        vector<int> new_rela[20001];
        for(int i = 1 ; i <= n ; i ++ ){
            for(int j = 0 ; j < cnt[i] ; j ++ ){
                new_rela[a[i][j].v].push_back(i) ;
            }
        }
        //以这个关系建立新的图   这个图的含义：从不是连接处的地方到另一个线路的地方的花费
        for(int i = 1 ; i <= m ; i ++ ){
            for(int j = 0 ; j < new_rela[i].size(); j ++ ){
                for(int g = 0 ; g < new_rela[i].size(); g ++ ){
                    if(j != g){
                        int u = new_rela[i][j];
                        int v = new_rela[i][g];
                        adj[u].push_back({v,2*num1});
                        adj[v].push_back({u,2*num1});
                    }
                }
            }
        }
        for(int i = 1 ; i <= n ; i ++ ){
            dijkstra(i);
        }
        while(q--){
            int s,e;
            cin >> s >> e ;
            ll ans = 1e18 ;
            for(int i = 0 ; i < new_rela[e].size() ; i ++ ){
                for(int j = 0 ; j < new_rela[s].size() ; j ++ ){
                    int u = new_rela[e][i];
                    int v = new_rela[s][j];
                     ans = min(dis[u][v]+2*num1,ans);
                }
            }
            cout << w[s]+ans+w[e]<<endl;
        }
        return 0;
    }
    handle();
    while(q--){
        int s,e;
        cin >> s >> e ;
        cout << w[s]+dp[s][e]+w[e] <<endl;
    }
    return 0;
}
//for my love !!
