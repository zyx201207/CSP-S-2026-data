#include<bits/stdc++.h>
using namespace std;
long long w[500009];
vector<long long> sta[500009];
unordered_map<long long,long long> ma[500009];
struct Edge{
    long long en;
    long long q;
};
vector<Edge> edge[500009];
long long dis[500009];
bool vis[500009];

long long dij(long long beginn,long long endd){
    if(beginn == endd){
        return 0;
    }
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[beginn] = 0;
    pq.push({0,beginn});
    while(!pq.empty()){
        auto v = pq.top();
        pq.pop();
        if(vis[v.second]){
            continue;
        }
        vis[v.second] = 1;
        for(auto u:edge[v.second]){
            if(dis[u.en] > dis[v.second] + u.q){
                dis[u.en] = dis[v.second] + u.q;
                pq.push({dis[u.en],u.en});

            }
            //pq.push({dis[u.en],u.en});
        }
    }
    /*if(dis[endd] == 0x3f3f3f3f3f3f3f3f){

        cerr << "ashdsjkf" ;
    }*/
    return dis[endd];
}

void solve(){
    long long x,y;
    cin >> x >> y;
    vector<long long> begins;
    vector<long long> ends;
    for(long long i:sta[x]){
        //cerr << i << endl;
        begins.push_back(i);
    }
    for(long long i:sta[y]){
        //cerr << i << endl;
        ends.push_back(i);
    }
    long long ans = 0x3f3f3f3f3f3f3f3f;
    for(long long i:begins){
        for(long long j:ends){
            ans = min(ans,dij(i,j) + w[x] + w[y] + ma[x][i] + ma[y][j]);
        }
    }
    cout << ans << endl;
    return ;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
   long long c,n,m,d,q;
   cin >> c >> n >> m >> d >> q;
    for(long long i = 1;i <= m;i++){
        cin >> w[i];
    }
    for(long long i = 1;i <= n;i++){
        long long k;
        cin >> k;
        for(long long j = 1;j <= k;j++){
            long long a,t;
            cin >> a >> t;
            sta[a].push_back(i);
            ma[a][i] = t;
        }


    }
    for(long long i = 1;i <= m;i++){
        for(long long j:sta[i]){
            for(long long k:sta[i]){
                if(k <= j){
                    continue;
                }
                edge[j].push_back({k,ma[i][j] + ma[i][k]});
                edge[k].push_back({j,ma[i][j] + ma[i][k]});
            }
        }
    }
    for(long long i = 1;i <= q;i++){
        solve();
    }
    return 0;
    /*long long x,y;
    cin >> x >> y;
    vector<long long> begins;
    vector<long long> ends;
    for(long long i:sta[x]){
        //cerr << i << endl;
        begins.push_back(i);
    }
    for(long long i:sta[y]){
        //cerr << i << endl;
        ends.push_back(i);
    }
    long long ans = 0x3f3f3f3f;
    for(long long i:begins){
        for(long long j:ends){
            ans = min(ans,dij(i,j) + w[x] + w[y] + ma[x][i] + ma[y][j]);
        }
    }
    cout << ans << endl;*/
}