#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'

const int maxn = 5e5 + 510, mod = 998244353;
const ll inf = 1e18;

ll tim[maxn];
vector<pair<int, ll>> edge[maxn];
int cnt;
int c, n, m, d, q;
ll dis[maxn];
ll E[510][510];

ll find(int x, int y){
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> qu;
    for(int i = 1; i <= cnt; i ++){
        dis[i] = inf;
    }
    qu.push({0, x});
    dis[x] = 0;
    while(qu.size()){
        int x = qu.top().second;
        ll dic = qu.top().first;
        qu.pop();
        if(dis[x] < dic) continue;
        for(auto i : edge[x]){
            int to = i.first;
            ll val = i.second;
            if(dis[to] > dic + val){
                dis[to] = dic + val;
                qu.push({dis[to], to});
            }
        }
    }
    return dis[y];
}

void solve1(){
    
    //cout << num << endl;
    while(q --){
        int x, y;
        cin >> x >> y;
        cout << find(x, y) + tim[x] + tim[y] << endl;
    }
}

void solve2(){
    for(int i = 1; i <= m; i ++){
        for(int j = 1; j <= m; j ++){
            E[i][j] = inf;
            if(i == j) E[i][j] = 0;
        }
    }

    for(int i = 1; i <= n; i ++){
        for(auto j : edge[i]){
            int u = j.first - n;
            ll val1 = j.second;
            for(auto k : edge[i]){
                int v = k.first - n;
                ll val2 = k.second;
                if(u == v) continue;
                ll sum =  min(E[u][v], val1 + val2);
                E[u][v] = sum;
                E[v][u] = sum;
            }
        }
    }

    for(int k = 1; k <= m; k ++){
        for(int i = 1; i <= m; i ++){
            for(int j = 1; j <= m; j ++){
                if(E[i][j] > E[i][k] + E[j][k]) E[i][j] = E[i][k] + E[j][k];
            }
        }
    }

    while(q --){
        int x, y;
        cin >> x >> y;
        ll ans = inf;
        for(auto i : edge[x]){
            int u = i.first - n;
            ll val1 = i.second;
            for(auto j : edge[y]){
                int v = j.first - n;
                ll val2 = j.second;
                ans = min(ans, val1 + val2 + tim[x] + tim[y] + E[u][v]);
            } 
        }
        cout << ans << endl;
    }

}

int main(){

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> c >> m >> n >> d >> q;
    for(int i = 1; i <= n; i ++){
        cin >> tim[i];
    }
    cnt = n;
    int k;
    int num = 0;
    for(int i = 1; i <= m; i ++){
        cin >> k;
        //num += k;
        ++ cnt;
        for(int j = 1; j <= k; j ++){
            ll x, y;
            cin >> x >> y;
            edge[cnt].push_back({x, y});
            edge[x].push_back({cnt, y});
            //num += 2;
        }
    }
    //cout << num;
    if(c <= 8) solve1();
    else solve2();


    return 0;
}
