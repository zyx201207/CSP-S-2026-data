#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
using namespace std;
const int N = 5e5 + 10;

int c,n,m,d,q,a[N];//地铁口->站厅；
vector<int> g[N];//可换乘的线路
vector<pair<int,int>> e[2 * N],b[2 * N];
int dis[2 * N];
map<pair<int,int>,int> mp;//线为f节点为s的价值

struct Node{
    int val,col;
};

void dijkstra(int st){
    queue<pair<int,Node>> q;
    memset(dis,0x3f,sizeof dis);
    dis[st] = 0,q.push({0,{st,-1}});
    while(!q.empty()){
        int u = q.front().second.val;
        int col = q.front().second.col;q.pop();
        for (auto i : e[u]){
            int v = i.first;
            int len = i.second;
            for (auto j : b[v]){
                int colv = j.first;
                if (col == colv && dis[v] > dis[u]){
                    dis[v] = dis[u];
                    q.push({-dis[v],{v,colv}});
                }
                if (col != colv && dis[v] > dis[u] + len){
                    dis[v] = dis[u] + len;
                    q.push({-dis[v],{v,colv}});
                }
            }
        }
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1;i <= m;i++) cin >> a[i];
    for (int i = 1;i <= n;i++){
        int k,x,y,last = 0;
        cin >> k;
        for (int j = 1;j <= k;j++){
            cin >> x >> y;
            b[x].push_back({i,y});
            mp[{i,x}] = y;
            if (j > 1){
                g[last].push_back(x);
                g[x].push_back(last);
            }last = x;
        }
    }
    for (int i = 1;i <= m;i++){
        for (auto x1 : b[i]){
            for (auto j : g[i]){
                for (auto x2 : b[j]){
                    int a1 = x1.first;
                    int a2 = x2.first;
                    int t1 = x1.second;
                    int t2 = x2.second;
                    e[i].push_back({j,t1 + mp[{a2,i}]});
                    e[j].push_back({i,t2 + mp[{a1,j}]});
                }
            }
        }
    }
    for (int i = 1;i <= m;i++){
        b[m + i].push_back({0,0});
        for (auto j : b[i]){
            e[m + i].push_back({i,a[i] + j.second});
            e[i].push_back({m + i,a[i] + j.second});
        }
    }
    int x,y;
    while(q--){
        cin >> x >> y;
        dijkstra(m + x);
        cout << a[x] + dis[m + y] << endl;
    }
    return 0;
}
