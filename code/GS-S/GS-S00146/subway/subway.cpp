#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int M = 5e5+5,N = 505;
int c,n,m,d,q;
int k[M];//k[i]:第i(1≤i≤n)条线路所经站数，k[i]<=5e5
ll w[M];//w[v]:第v(1≤v≤m)个地铁站,从地铁口走到站厅耗时，w[v]<=1e9
//vector <pair<int,ll>> e[N];//e[i]:第i条线路所有{经过的站点a，从线路i站台到a站厅时间}
vector <pair<int,ll>> lines[M];//lines[i]:第i个站点被哪些线路经过，从站台i到每个线路的时间
ll dist[505][505];//dist[i][j]:从线路i到线路j的时间

ll length(int x,int y){//提示：d<=20
    ll res = 1e18;
    auto& p1 = lines[x],p2 = lines[y];
    int sz1 = p1.size(),sz2 = p2.size();
    for (int i = 0;i < sz1;i++){
        for (int j = 0;j < sz2;j++){
            int u = p1[i].first,v = p2[j].first;
            ll w1 = p1[i].second,w2 = p2[j].second;
            res = min(res,dist[u][v]+w1+w2);
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("subway.in","r",stdin);//必须检查！必须检查！必须检查！
    freopen("subway.out","w",stdout);//必须检查！必须检查！必须检查！
    //输入
    cin >> c >> n >> m >> d >> q;
    for (int i = 1;i <= m;i++) cin >> w[i];
    for (int i = 1;i <= n;i++){
        cin >> k[i];
        for (int j = 1;j <= k[i];j++){
            int a;ll t;
            cin >> a >> t;
//            e[i].push_back({a,t});
            lines[a].push_back({i,t});
        }
    }
    //检查输入
//    for (int i = 1;i <= m;i++) cout << w[i] << ' ';
//    for (int i = 1;i <= n;i++) cout << k[i] << ' ';
//    for (int i = 1;i <= n;i++){
//        for (auto p:e[i]){
//            int v = p.first;ll w = p.second;
//            cout << v << ' ' << w << '\n';
//        }
//    }
    fill(dist[0],dist[0]+N*N,1e17);
    for (int i = 1;i <= n;i++) dist[i][i]=0;
    for  (int i = 1;i <= m;i++){
//        cout << i << ':';
        int sz = lines[i].size();
        auto& p = lines[i];
        if (sz < 2) continue;
        for (int l = 0;l < sz;l++){
            for (int r = l+1;r < sz;r++){
                int u = p[l].first,v = p[r].first;
                dist[u][v] = min(dist[u][v] , p[l].second+p[r].second);
                dist[v][u] = min(dist[v][u] , p[l].second+p[r].second);
//                cout << p[l].first << ',' << p[l].second << ' ' << p[r].first << ',' << p[r].second << '\n';
//                cout << lines[i]
            }
        }
    }
    //floyd
    for (int k = 1;k <= n;k++){
        for (int i = 1;i <= n;i++){
            for (int j = 1;j <= n;j++){
                if (dist[i][j] > dist[i][k]+dist[k][j]) dist[i][j] = dist[i][k]+dist[k][j];
            }
        }
    }
    //时间消耗本质上是在线路之间的换乘上
    //线路数量相对较少
    //对线路之间floyd！！！
    //如何求得两条线路之间的换乘时间？
    //找到交点。因为d<=20,每个站点最多有20条线路经过
//    for (int i = 1;i <= n;i++){//检查floyd算法
//        for (int j = 1;j <= n;j++) cout << dist[i][j] << ' ';
//        cout << '\n';
//    }

    //处理查询
    //问题：如何将站点之间的距离和线路之间的距离结合起来
    while(q--){
        int x,y;
        cin >> x >> y;
        ll ans = w[x]+w[y]+length(x,y);
        cout << ans << '\n';
    }
    return 0;
}

//struct DSU{
//    int fa[M]={0},h[M]={0};
//    void init(int n){ for (int i = 1;i <= n;i++) fa[i]=i,h[i]=1; }
//    int getfa(int x) { return fa[x]==x ? x:fa[x]=getfa(fa[x]); }
//    void unite(int a,int b){
//        a = getfa(a),b = getfa(b);
//        if (a == b) return;
//        if (h[a] < h[b]) swap(a,b);
//        fa[b]=a;
//        if (h[a]==h[b]) h[a]++;
//    }
//}dsu;
